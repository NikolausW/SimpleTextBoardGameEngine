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
      //players vector
      //GameState* gamestate
      //PlaySpace* playspace when implemented 
      //Turn* Turn Pretty sure I can just use the base implementation for this
      //TTTDialog* when implemented

      //bool Round_Over(void) BASE IMPLEMENTATION
      //void Execute_Turn(void) BASE IMPLEMENTATIO
      void Process_Move(Game::Move* move);
      //size_t Player_X_Turn(void) BASE IMPLEMENTATION
      //void Round_End(void) BASE IMPLEMENTATION
      //void Play_Again(bool again) BASE IMPLEMENTATION
  };
}
#endif
