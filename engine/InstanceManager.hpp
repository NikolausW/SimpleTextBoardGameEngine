///////////////////////////////////////////////
#ifndef INSTANCEMANAGER_HPP
#define INSTANCEMANAGER_HPP
///////////////////////////////////////////////
#include <vector> //Vector of Players
#include <string> //Setup Dialog
#include "Dialog.hpp" //Setup Dialog
#include "GamePlay.hpp" //Game Pointer

class InstanceManager
{
  public:
    InstanceManager();
    void Instance_Loop(void);
  private:
    std::vector<GamePlay::Player> playerlist;
    GamePlay::Game* currentgame;
    Game_Select gameselect; //Option Select for picking game to be played
    Dialog::Instance dialog;

    void Different_Game(void);
    void Exit(void);
};

class Game_Select : Dialog::Option_Select
  {
  public:
    static Game_Select* option_select();
  protected:
    void Generate_List(void);
  private:
    Game_Select();
    static Game_Select* Instance;
  };

class Game_Option : public Dialog::Option
{
  public:
    Game_Option(int number, GamePlay::Game* game);
    GamePlay::Game* On_Select(void); //Game_Select
  private:
    GamePlay::Game* selection;
};

#endif
