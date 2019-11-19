///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
#include "GamePlay.hpp"

namespace Dialog
{
  void Welcome(void);
  GamePlay::Game* Game_Select(void);
  bool Play_Again(void);
  void Thanks(void);

  class GamePlay_Dialog
  {
    void Player_Select(int numPlayers);
    void Player_Setup(GamePlay::Player* newPlayer);
    void Turn_Prompt(void); //This needs to be fleshed out
    bool virtual Validate_Input(void) = 0;
  };
}

#endif

