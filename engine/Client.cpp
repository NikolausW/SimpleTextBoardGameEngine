#include "Client.hpp"

namespace Client
{
  Instance::Instance()
  {
    playerlist.clear(); // Replace if/when this is saved in a seperate file
    //dialog decalred, should not need to be initialized
    Instance_Loop();
  }

  void Instance::Instance_Loop()
  {
    dialog.Prompt(dialog.welcome.length(), dialog.welcome);
    currentgame = new Game::Base(gamedata);
    while(currentgame)
    {
      currentgame->Game_Loop();
      Different_Game();
    }
    Exit();
  }

  void Instance::Different_Game()
  {
    currentgame = NULL; // replace this with proper destructor
    std::cout << "Would you like to play another game?" << std::endl; //replace with dialog
    if(dialog.YesNo->Select())
    {
      currentgame = new Game::Base(gamedata);
    }
  }

  void Instance::Exit()
  {
    std::cout << dialog.thankYou << std::endl; //replace with prompt
  }

  Client_Dialog::Client_Dialog()
  {
    gameselect = Game_Select::Get_Instance();
    welcome = "Welcome"; //ascii art replacement
    thankYou = "Thank you for playing!"; //ascii art replacement
  };

  Game_Select* Game_Select::Get_Instance()
  {
    if(!Instance)
    {
      Instance = new Game_Select;
    }
    return Instance;   
  }

  void Game_Select::Generate_List(void)
  {
    Game::PopulateGameList(Options);
  }

  Game_Select::Game_Select()
  {
    Generate_List();    
  }
}
