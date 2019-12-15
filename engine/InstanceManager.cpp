#include "InstanceManager.hpp"

InstanceManager::InstanceManager()
{ 
  gameselect = OptionSelect::Game::option_select();
  Instance_Loop();
  Exit();
}

void InstanceManager::Instance_Loop()
{
  dialog.Prompt(dialog.welcome.length(), dialog.welcome);
  //currentgame = gameselect.Select()->On_Select(); //Need to create method for base option probably?

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
    //currentgame = gameselect.Select()->On_Select();
  }
}

void InstanceManager::Exit()
{
  std::cout << dialog.thankYou << std::endl;
}



