#include "InstanceManager.hpp"

InstanceManager::InstanceManager()
{
  dialog = new Dialog::Instance();
  //dialog->Prompt() Welcome Dialog
  CurrentGame = dialog->Game_Select();
  Instance_Loop();
}

void InstanceManager::Instance_Loop()
{
  while(CurrentGame)
  {
    CurrentGame->Game_Loop();
    //Delete CurrentGame
    //dialog->Prompt() Play a Different Game
    Different_Game();
  }
  Exit();
}


void InstanceManager::Different_Game()
{
  CurrentGame = dialog->Game_Select();
}

void InstanceManager::Exit()
{
  //dialog->Prompt() Thanks for playing
}
