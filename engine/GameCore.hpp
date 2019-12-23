///////////////////////////////////////////////
#ifndef GAMECORE_HPP
#define GAMECORE_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include "GameComponents.hpp"
#include <vector>

namespace Game
{
  class Base
  {
    public:
      Locations* locations;
      Pieces* pieces;
      virtual void Game_Loop(void);
    protected:
      int num_players,
          turn_number;
      std::vector<Move*> turns; //stores squares played to, this should be change to move/move*, there's no guarntee that turns will always just be an int
      std::vector<const int> board; //current game/board state   Could change this to <int> or whatever format the enum is, but that forces an enum
      std::vector<Player*> players ; // Players actively in this game instance 
      PlaySpace* playspace; // Pointer to Playspace for this game
      //AI* ai; // Ai pointer for this game, NULL if not available/implemented
      Turn* turn; // Pointer to game turn logic
      BaseDialog* dialog; // dialog for this game type, need to split off turn dialog

      virtual bool Round_Over(void); // Checks if Round is over
      virtual bool Round_Won(void) = 0; // Checks if Round is won
      virtual bool Round_Tie(void) = 0; // Checks if the Round results in a tie
      virtual void Execute_Turn(void); 
      virtual size_t Player_X_Turn(void); // Returns size_t current player turn number
      virtual void Process_Move(Move* move) = 0; // This will parse the move object
      virtual void Round_End(void); // Prompts Play Again, Could be moved to dialog instance
      virtual void Play_Again(bool again); // Resets gamestate and calls another game loop
      virtual void Reset(void) = 0; // Resets gamestate
  };
}
#endif
