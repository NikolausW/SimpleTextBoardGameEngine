///////////////////////////////////////////////
#ifndef CLIENT_HPP
#define CLIENT_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include "GameCore.hpp"
#include "GameComponents.hpp"
#include "GameList.hpp"
#include <iostream>

namespace Client
{
  class Game_Select : public Dialog::Option_Select //why did I make this a singleton?
  {
    public:
      static Game_Select* option_select();
      virtual Game::Option* Select(void);
    protected:
      void Generate_List(void);
    private:
      static Game_Select* Instance;
      Game_Select();
  };

  class Client_Dialog : public Dialog::Base
  {
    //Need to include strings for Welcome, Play_Again, and Thank you 
    public:
      Client_Dialog();
      Game_Select* gameselect;
      std::string welcome,
                  thankYou;
  };

  class Instance
  {
    public:
      Instance();
      void Instance_Loop(void);
    private:
      std::vector<Game::Player> playerlist;
      Game::Base* currentgame;
      Client_Dialog dialog;

      void Different_Game(void);
      void Exit(void);
  };
}
#endif
