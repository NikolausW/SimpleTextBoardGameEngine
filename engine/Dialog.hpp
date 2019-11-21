///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
#include "Player.hpp"
//#include "GamePlay.hpp"
#include <string>
#include <iostream>


namespace Dialog
{
  class Dialog
  {
    public:
      virtual void Prompt(size_t width, std::string str);
      virtual std::string Receive_Input(size_t length);
      virtual bool Validate_Input(std::string input) = 0;
      virtual bool YesNo(void);
  };

  class Instance : public Dialog
  {
    //Need to include strings for Welcome, Play_Again, and Thank you, Prompt and YesNo
    public:
     // virtual GamePlay::Game* Game_Select(void);
  };

  class Game : public Dialog
  {
    //Need to include strings for Turn and Again Prompt, Round Winner, and Round Tie
    public:
      virtual void Player_Select(int numPlayers);
      virtual void Player_Setup(GamePlay::Player* newPlayer);
  };
}

#endif
