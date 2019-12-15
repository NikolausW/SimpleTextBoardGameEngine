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
      virtual void Game_Loop(void);
    protected:
      int num_players,
          turn_number;
      enum Pieces{};
      std::vector<int> turns, //stores squares played to, should probably be an option 
                       board; //current game/board state
      std::vector<Player*> players ; // Players actively in this game instance 
      PlaySpace* playspace; // Pointer to Playspace for this game
      AI* ai; // Ai pointer for this game, NULL if not available/implemented
      Turn* turn; // Pointer to game turn logic
      BaseDialog* dialog; // dialog for this game type, need to split off turn dialog

      virtual bool Round_Over(void); // Checks if Round is over
      virtual bool Round_Won(void) = 0; // Checks if Round is won
      virtual bool Round_Tie(void) = 0; // Checks if the Round results in a tie
      virtual Move Execute_Turn(void); //why does this return an int?
      virtual size_t Player_X_Turn(void); // Returns size_t current player turn number
      virtual void Process_Move(void) = 0; // This will parse the move object
      virtual void Round_End(void); // Prompts Play Again, Could be moved to dialog instance
      virtual void Play_Again(bool again); // Resets gamestate and calls another game loop
      virtual void Reset(void) = 0; // Resets gamestate
  };
}
#endif
