///////////////////////////////////////////////
#ifndef GAMECORE_HPP
#define GAMECORE_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include "Option.hpp"
#include <string>
#include <vector>

namespace GameCore
{
  class Game
  {
    public:
      virtual void Game_Loop(void);
    private:
      int num_players,
          turn_number;
      enum Pieces{};
      std::vector<int> turns, //stores squares played to, should probably be an option 
                       board; //current game/board state
      std::vector<Option::Player*> players; // Players actively in this game instance 
      PlaySpace* playspace; // Pointer to Playspace for this game
      AI* ai; // Ai pointer for this game, NULL if not available/implemented
      Turn* turn; // Pointer to game turn logic
      Dialog::Game* dialog; // dialog for this game type, need to split off turn dialog

      virtual bool Round_Over(void); // Checks if Round is over
      virtual bool Round_Won(void) = 0; // Checks if Round is won
      virtual bool Round_Tie(void) = 0; // Checks if the Round results in a tie
      virtual int Execute_Turn(void); //why does this return an int?
      virtual size_t Player_X_Turn(void); // Returns size_t current player turn number
      virtual void Process_Move(void) = 0;
      virtual void Round_End(void); // Prompts Play Again, Could be moved to dialog instance
      virtual void Play_Again(bool again); // Resets gamestate and calls another game loop
      virtual void Reset(void) = 0;
  }; 

  class PlaySpace
  {
    public:
      void Write_PlaySpace(void);
      void New_Game(void);
    protected:
      std::string display;
      size_t height, width;

      void Write_Header(void);
      void Write_Board(void);
      void Print_PlaySpace(void);
      void Clear_Board(void);
  };

  class Turn
  {
    public:
      AI* ai;
      Dialog::Dialog* dialog; //Place Holder plz fix
      
      virtual int AI(void);
      virtual int Player(void);
      virtual bool Valid_Input(char input) = 0; //What does this do?
  };
  
  class AI
  {
    public:
      virtual int Turn(void) = 0;
  };
}
#endif
