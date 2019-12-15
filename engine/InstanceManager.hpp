///////////////////////////////////////////////
#ifndef INSTANCEMANAGER_HPP
#define INSTANCEMANAGER_HPP
///////////////////////////////////////////////
#include <vector> //Vector of Players
#include <string> //Setup Dialog
#include "Dialog.hpp" //Setup Dialog
#include "GameCore.hpp" //Game Pointer
#include "Option.hpp"
#include "OptionSelect.hpp"

class InstanceManager
{
  public:
    InstanceManager();
    void Instance_Loop(void);
  private:
    std::vector<Option::Player> playerlist;
    GameCore::Game* currentgame;
    OptionSelect::Game* gameselect; //Option Select for picking game to be played
    Dialog::Instance dialog;

    void Different_Game(void);
    void Exit(void);
};
#endif
