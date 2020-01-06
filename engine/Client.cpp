#include "Client.hpp"

namespace Client
{
  Instance::Instance()
  {
    playerlist.clear(); // Replace if/when this is saved in a seperate file
    dialog = new Client_Dialog(playerlist);
    Instance_Loop();
  }

  void Instance::Instance_Loop()
  {
    dialog->Prompt(dialog->welcome.length(), dialog->welcome);
    currentgame = dialog->gameselect->Select().On_Select();
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
    if(dialog->YesNo->Select().On_Select())
    {
      currentgame = dialog->gameselect->Select().On_Select();
    }
  }

  void Instance::Exit()
  {
    std::cout << dialog->thankYou << std::endl; //replace with prompt
  }

  Client_Dialog::Client_Dialog(std::vector<Game::Player>& Client_List) : Dialog::Base()
  {
    gameselect = Game_Select::Get_Instance(Client_List);
    welcome = "Welcome"; //ascii art replacement
    thankYou = "Thank you for playing!"; //ascii art replacement
  };

  Game_Select* Game_Select::Get_Instance(std::vector<Game::Player>& Client_List)
  {
    if(!Instance)
    {
      Instance = new Game_Select(Client_List);
    }
    return Instance;   
  }

  void Game_Select::Generate_List(void)
  {
    Game::PopulateGameList(Options, *client_list);
  }

  Game_Select::Game_Select(std::vector<Game::Player>& Client_List) : Dialog::Option_Select<Game::Option>(input_length)
  {
    client_list = &Client_List;
    input_length = 1;
    Generate_List();    
  }
}
