#include "InstanceManager.hpp"

InstanceManager::InstanceManager()
{  
  Instance_Loop();
  Exit();
}

void InstanceManager::Instance_Loop()
{
  dialog.Prompt(dialog.welcome.length(), dialog.welcome);
  currentgame = gameselect->Select()->On_Select(); //need to make game objects to see if this actually works

  while(currentgame)
  {
    currentgame->Game_Loop;
    Different_Game();
  }
  Exit();
}

void InstanceManager::Different_Game()
{
  currentgame = NULL;
  std::cout << "Would you like to play another game?" << std::endl;
  if(dialog.YesNo->Select())
  {
    currentgame = gameselect->Select()->On_Select();
  }
}

void InstanceManager::Exit()
{
  std::cout << dialog.thankYou << std::endl;
}

Game_Select* Game_Select::option_select()
{
  if(!Instance)
  {
    Instance = new Game_Select;
  }
  return Instance;   
}

void Game_Select::Generate_List(void)
{
  //List = GameList List;
}

Game_Option::Game_Option(int number, GamePlay::Game* game)
{
  Required_Input = std::to_string(number);
  selection = game;
}

GamePlay::Game* Game_Option::On_Select(void)
{
  return selection;
}