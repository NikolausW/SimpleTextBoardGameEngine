#include "Dialog.hpp"

namespace Dialog
{
  template <class T>
  Option<T>::Option(T Selection, std::string Name, std::string Required_Input)
  {
    name = Name;
    required_input = Required_Input;
    selection = Selection;
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
  T Option_Select<T>::Select()
  {
    // Generate_List, should this have a conditional to only run once if needed?
    if(Options.size() == 1)
    {
      return Options[0];
    }
    else
    {
      Print_List();
      while(!Validate_Input(Take_Input()))
        ; // do nothing
      return Process_Input();
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
  std::string Option_Select<T>::Generate_Option_String(T* option)
  {
    std::ostringstream ss;
    try
    {
      ss << option->Required_Input << ") " << option->Name;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      abort();
    }   
    return ss.str();
  }

  template <class T>
  std::string Option_Select<T>::Take_Input()
  {
    std::string input;
    getline(std::cin, input);
    input.resize(this->input_length); // If input too short could have it fill in with a character
    return input;
  }

  template <class T>
  bool Option_Select<T>::Validate_Input(std::string& input)
  {
    for(int i = 0; i < this->Options.size(); i++)
    {
      try
      {
        if(input == this->Options[i].required_input)
        {
          if(!this->Options[i].Conditional())
          {
            return false;
          }
          else
          {
            this->user_input = input;
            return true;            
          }        
        }
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }  
    }
    return false;
  }

  template <class T>
  T* Option_Select<T>::Process_Input()
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(this->user_input == this->Options[i].required_input)
      {
        return &Options[i];
      }
    }
    std::cout << "Error: Validated Input Not Found";
    abort();
  }

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
    if(option->required_input == "y")
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
    Options.push_back(Option(true, "Yes", "y"));
    Options.push_back(Option(true, "No", "n"));
  }

  YesNo_Select::YesNo_Select()
  {
    input_length = 1;
    Generate_List(); // likely remove this
  }

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
}
