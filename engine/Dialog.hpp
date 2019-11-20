///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
#include "Player.hpp"


namespace Dialog
{
  void Welcome(void);
  void Game_Select(void);
  bool Play_Again(void);
  void Thanks(void);

  class Dialog
  {
    public:
      virtual void Player_Select(int numPlayers);
      virtual void Player_Setup(GamePlay::Player* newPlayer);
      virtual char Turn_Prompt(bool bad_input); 
      virtual bool Again_Prompt(void);
      virtual void Round_Winner(std::string Name);
      virtual void Tie(void);
  };
}

#endif

