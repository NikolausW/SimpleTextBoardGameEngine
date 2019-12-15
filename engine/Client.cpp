#include "Client.hpp"

namespace Client
{
  Instance::Instance()
  {
    Instance_Loop();
    Exit();
  }

  void Instance::Instance_Loop()
  {
    dialog.Prompt(dialog.welcome.length(), dialog.welcome);
    currentgame = dialog.gameselect->Select()->On_Select(); //Need to create method for base option probably?

    while(currentgame)
    {
      currentgame->Game_Loop();
      Different_Game();
    }
    Exit();
  }

  void Instance::Different_Game()
  {
    currentgame = NULL;
    std::cout << "Would you like to play another game?" << std::endl;
    if(dialog.YesNo->Select())
    {
      currentgame = dialog.gameselect->Select()->On_Select();
    }
  }

  void Instance::Exit()
  {
    std::cout << dialog.thankYou << std::endl;
  }

  Client_Dialog::Client_Dialog()
  {
    gameselect = Game_Select::option_select();
    welcome = "Welcome";
    thankYou = "Thank you for playing!";
  };

  Game_Select* Game_Select::option_select()
  {
    if(!Instance)
    {
      Instance = new Game_Select;
    }
    return Instance;   
  }

  Game::Option* Game_Select::Select()
  {
    Game::Option* selection;

    Print_List();
    while(!Validate_Input(Take_Input()))
      ; // do nothing
    return selection;
  };

  void Generate_List(void)
  {
    //List = GameList List;
  }

  Game_Select::Game_Select()
  {
    Generate_List();    
  }
}
