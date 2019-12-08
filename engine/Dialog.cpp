#include "Dialog.hpp"
#include <string>
#include <sstream>

namespace Dialog
{
  void Dialog::Prompt(size_t width, std::string str)
  {
    for(size_t i = 0; i < str.length(); i += width)
    {
      std::cout << str.substr(i, width) << std::endl;
    }
  }

  void Dialog::Clear_Screen()
  {
    for(int i = 50; i > 0; i--)
    {
      std::cout << "\n";
    }
  }

  Instance::Instance()
  {
    welcome = "Welcome";
    thankYou = "Thank you for playing!";
  };

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
    for(int i = 0; i < List.size(); i++)
    {
      if(List[i].Conditional())
      {
        std::cout << Generate_Option_String(&List[i]) << std::endl;
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
    for(int i = 0; i < List.size(); i++)
    {
      if(input == List[i].Required_Input)
      {
        if(!List[i].Conditional()){return false;}
        else{return true;}        
      }
    }
    return false;
  }

  Yes_No* Yes_No::option_select()
  {
    if(!Instance)
    {
      Instance = new Yes_No;
    }
    return Instance;
  }

  void Yes_No::Print_List(void)
  {
    std::cout << "Yes(y) / No(n)? :";
  }

  std::string Yes_No::Generate_Option_String(Option* option)
  {
    //do nothing
  }

  void Yes_No::Generate_List()
  {
    List.push_back(YN_Option(true));
    List.push_back(YN_Option(false));
  }

  Yes_No::Yes_No()
  {
    Input_Length = 1;
    Generate_List();
  }

  bool Option::Conditional()
  {
    return true;
  }

  YN_Option::YN_Option(bool YN)
  {
    selection = YN;
    if(selection){Name = "Yes"; Required_Input = "y";}
    else {Name = "No"; Required_Input = "n";}
  }

  bool YN_Option::On_Select()
  {
    return selection;
  }
}
