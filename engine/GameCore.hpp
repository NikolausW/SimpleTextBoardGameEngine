///////////////////////////////////////////////
#ifndef GAMECORE_HPP
#define GAMECORE_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include "GameComponents.hpp"
#include "GameList.hpp"
#include <vector>

namespace Game
{
  class Base
  {
    public:
      Base(GameData& data);
      const Locations* locations;
      const Pieces* pieces;
      virtual void Game_Loop(void);
    protected:
      int player_count;
      std::vector<Player*> players ; // Players actively in this game instance
      GameState* gamestate; // Current state of the game, updated every turn
      PlaySpace* playspace; // Pointer to Playspace for this game
      Turn* turn; // Pointer to game turn logic
      BaseDialog* dialog; // dialog for this game type, need to split off turn dialog

      virtual bool Round_Over(void); // Checks if Round is over  
      virtual void Execute_Turn(void); 
      virtual size_t Player_X_Turn(void); // Returns size_t current player turn number
      virtual void Process_Move(Move* move);
      virtual void Round_End(void); // Prompts Play Again, Could be moved to dialog instance
      virtual void Play_Again(bool again); // Resets gamestate and calls another game loop
    private:
      Base();    
  };
}
#endif