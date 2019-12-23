///////////////////////////////////////////////
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
///////////////////////////////////////////////
#include "../../engine/GameCore.hpp" //Base Game 
#include "../../engine/GameComponents.hpp" //AI, Players, Playspace, Turn, Dialog
#include "T3AI.hpp" //This might end up being circular, need to watch for that
#include "T3Components.hpp"
#include "T3PlaySpace.hpp"
#include <vector>

namespace TicTacToe
{
  class TTT : public Game::Base
  {
    public:
      TTT(); //Constructor
      //Locations locations;
      //Pieces pieces;
      //virtual void Game_Loop(void) BASE IMPLEMENTATION
    protected:
      //num_players = 2
      //turn number starts at 0
      //turns vector
      //board vector
      //players vector
      //PlaySpace* playspace when implemented 
      //Turn* Turn Pretty sure I can just use the base implementation for this
      //TTTDialog* when implemented

      //bool Round_Over(void) BASE IMPLEMENTATION
      bool Round_Won(void); //checks if Round is won
      bool Round_Tie(void); //checks if the Round results in a tie
      //void Execute_Turn(void) BASE IMPLEMENTATION
      //size_t Player_X_Turn(void) BASE IMPLEMENTATION
      void Process_Move(Game::Move* move);
      //void Round_End(void) BASE IMPLEMENTATION
      //void Play_Again(bool again) BASE IMPLEMENTATION
      void Reset(void);
  };
}
#endif
