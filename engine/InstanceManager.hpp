///////////////////////////////////////////////
#ifndef INSTANCEMANAGER_HPP
#define INSTANCEMANAGER_HPP
///////////////////////////////////////////////
#include <vector> //Vector of Players
#include <string> //Setup Dialog
#include "Dialog.hpp" //Setup Dialogshrug
#include "GamePlay.hpp" //Game Pointer

class InstanceManager
{
  public:
    InstanceManager();
    void Instance_Loop(void);
  private:
    std::vector<GamePlay::Player> PlayerList;
    GamePlay::Game* CurrentGame;
    Dialog::Dialog* Dialog;

    void Different_Game(void);
    void Exit(void);
};




#endif