#include "OptionSelect.hpp"

namespace OptionSelect
{
  Option::Option* Option_Select::Select()
  {
    Option::Option* selection;

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
  
  std::string Option_Select::Generate_Option_String(Option::Option* option)
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

  std::string Yes_No::Generate_Option_String(Option::Option* option)
  {
    //do nothing
  }

  void Yes_No::Generate_List()
  {
    List.push_back(Option::YesNo(true));
    List.push_back(Option::YesNo(false));
  }

  Yes_No::Yes_No()
  {
    Input_Length = 1;
    Generate_List();
  }

  Player::Player(int numPlayers)
  {
    for(int i = numPlayers; i > 0; i--)
    {
      
    }
  }

  //MOVE SELECT GOES HERE

  Game* Game::option_select()
  {
    if(!Instance)
    {
      Instance = new Game;
    }
    return Instance;   
  }

  void Generate_List(void)
  {
    //List = GameList List;
  }  
}
