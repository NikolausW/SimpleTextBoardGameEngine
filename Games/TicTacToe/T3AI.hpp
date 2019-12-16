///////////////////////////////////////////////
#ifndef T3AI_HPP
#define T3AI_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp" // Base AI

namespace TicTacToe
{
  class TTT_AI : public Game::AI
  {
    public:
      Game::Move* Turn(void);
    protected:
    //"Random" Selection
      Game::Move* Random_Corner(void);
      //Game::Move* Either(Move a, Move b);
      //Game::Move* Open_Space(void);
    private:
    //Logic Per Turn
      Game::Move* Turn_One(void);
      Game::Move* Turn_Two(void);
      Game::Move* Turn_Three(void);
      Game::Move* Turn_Four(void);
      Game::Move* Turn_Five_Six_Seven(void);
      Game::Move* Turn_Eight_Nine(void);
    //Winning Move Logic
      Game::Move* WinningMove(int prev_turn);
      Game::Move* DoubleWinCondition(int prev_turn);
      Game::Move* Single_Win_Condition(void);
  };
}
#endif
