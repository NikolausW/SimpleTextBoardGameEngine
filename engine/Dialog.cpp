#include "Dialog.hpp"

namespace Dialog
{
  Base::Base(void)
  {
    YesNo = YesNo_Select::Get_Instance();
  }

  void Base::Prompt(size_t width, std::string str)
  {
    for(size_t i = 0; i < str.length(); i += width)
    {
      std::cout << str.substr(i, width); // << std::endl;
    }
  }

  void Base::Clear_Screen()
  {
    for(int i = 50; i > 0; i--)
    {
      std::cout << "\n";
    }
  }

  template <class T>
  bool Option<T>::Conditional()
  {
    return true;
  }

  template <class T>
  T Option<T>::On_Select()
  {
    return selection;
  }

  template <class T>
  Option_Select<T>::Option_Select()
  {
    Generate_List();
  }

  template <class T>
  Option<T>* Option_Select<T>::Select()
  {
    Option<T>* selection;

    if(Options.size() == 1)
    {
      selection = &Options[0];
    }
    else
    {
      Print_List();
      while(!Validate_Input(Take_Input()))
        ; // do nothing
      selection = Process_Input();
    }
    return selection;
  };

  template <class T>
  void Option_Select<T>::Print_List()
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(Options[i].Conditional())
      {
        std::cout << Generate_Option_String(&Options[i]) << std::endl;
      }
    }
  }
  
  template <class T>
  std::string Option_Select<T>::Generate_Option_String(Option<T>* option)
  {
    std::ostringstream ss;
    ss << option->Required_Input << ") " << option->Name;
    return ss.str();
  }

  template <class T>
  std::string Option_Select<T>::Take_Input()
  {
    std::string input;
    getline(std::cin, input);
    input.resize(Input_Length); // If input too short could have it fill in with a character
    return input;
  }

  template <class T>
  bool Option_Select<T>::Validate_Input(std::string input)
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(input == Options[i].Required_Input)
      {
        if(!Options[i].Conditional())
        {
          return false;
        }
        else
        {
          return true;
          User_Input = input;
        }        
      }
    }
    return false;
  }

  template <class T>
  Option<T>* Option_Select<T>::Process_Input()
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(User_Input == Options[i].Required_Input)
      {
        return &Options[i];
      }
    }
    std::cout << "Error: Validated Input Not Found";
    abort();
  }

  YesNo_Option::YesNo_Option(bool YN) 
  {
    if(YN)
    {
      Name = "Yes"; 
      Required_Input = "y";
    }
    else 
    {
      Name = "No"; 
      Required_Input = "n";
    }
  }

  /* Likely to be deleted as redundant 
  bool YesNo_Option::On_Select()
  {
    return selection;
  }
  */

  YesNo_Select* YesNo_Select::Get_Instance()
  {
    if(!Instance)
    {
      Instance = new YesNo_Select;
    }
    return Instance;
  }

  void YesNo_Select::Print_List(void)
  {
    std::cout << Generate_Option_String(&Options[0]) << " / " << Generate_Option_String(&Options[1]) << "? :";
  }

  std::string YesNo_Select::Generate_Option_String(Option<bool>* option)
  {
    if(option->Required_Input == "y")
    {
      return "Yes(y)";
    }
    else
    {
      return "No(n)";
    }  
  }

  void YesNo_Select::Generate_List()
  {
    Options.push_back(YesNo_Option(true));
    Options.push_back(YesNo_Option(false));
  }

  YesNo_Select::YesNo_Select()
  {
    Input_Length = 1;
    Generate_List();
  }
}
