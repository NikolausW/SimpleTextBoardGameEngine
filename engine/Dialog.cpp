#include "Dialog.hpp"

namespace Dialog
{
  Base::Base(void)
  {
    YesNo = YesNo_Select::option_select();
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

  bool Option::Conditional()
  {
    return true;
  }

  Option* Option_Select::Select()
  {
    Option* selection;

    Print_List();
    while(!Validate_Input(Take_Input()))
      ; // do nothing
    return selection;
  };

  void Option_Select::Print_List()
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(Options[i].Conditional())
      {
        std::cout << Generate_Option_String(&Options[i]) << std::endl;
      }
    }
  }
  
  std::string Option_Select::Generate_Option_String(Option* option)
  {
    std::ostringstream ss;
    ss << option->Required_Input << ") " << option->Name;
    return ss.str();
  }

  std::string Option_Select::Take_Input()
  {
    std::string input;
    getline(std::cin, input);
    input.resize(Input_Length);
    return input;
  }

  bool Option_Select::Validate_Input(std::string input)
  {
    for(int i = 0; i < Options.size(); i++)
    {
      if(input == Options[i].Required_Input)
      {
        if(!Options[i].Conditional()){return false;}
        else{return true;}        
      }
    }
    return false;
  }

  YesNo_Option::YesNo_Option(bool YN)
  {
    selection = YN;
    if(selection){Name = "Yes"; Required_Input = "y";}
    else {Name = "No"; Required_Input = "n";}
  }

  bool YesNo_Option::On_Select()
  {
    return selection;
  }

  YesNo_Select* YesNo_Select::option_select()
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

  std::string YesNo_Select::Generate_Option_String(Option* option)
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
