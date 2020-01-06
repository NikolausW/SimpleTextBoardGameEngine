///////////////////////////////////////////////
#ifndef T3COMPONENTS_HPP
#define T3COMPONENTS_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp"

namespace TicTacToe
{
  struct TTT_Locations : public Game::Locations
  {
    const static int Square_One = 1,
                 Square_Two = 2,
                 Square_Three = 3,
                 Square_Four = 4,
                 Square_Five = 5,
                 Square_Six = 6,
                 Square_Seven = 7,
                 Square_Eight = 8,
                 Sqaure_Nine = 9,
                 //Undo = 1000
                 //Redo = 1001
                 Board_Horizontal1 = 1002,
                 Board_Horizontal2 = 1003,
                 Board_Vertical_Start = 1004,
                 Header_Name1 = 1005,
                 Header_Name2 = 1006,
                 Header_Score1 = 1007,
                 Header_Score2 = 1008;
  };

  struct TTT_Pieces : public Game::Pieces
  {
                  // Blank = 0;
    const static int Cross = 1,
                     Circle = 2;
  };
  
  class TTT_GameState : public Game::GameState
  {
    public:
      enum Status{Won, Winnable, Undecided, Unwinnable};
      TTT_GameState();
      //int turn number;
      //std::vector<Move*> turns;
      //std::vector<const int> board;
      bool Round_Won(void);
      bool Round_Tie(void);    
      void Reset(void);
      Status Square_Status(const Game::Location square);
      Status Row_Status(const int Row_Number);
      Status Column_Status(const int Column_Number);
      Status Diagnol_Status(const int Diagnol_Number);
  };

  class TTT_Move_Select : public Game::Move_Select 
  {
    public:
      TTT_Move_Select();
      //Move* Select(void); ??? BASE BASE IMPLEMENTATION???
    protected:
      //void Print_List(void); BASE IMPLEMENTATION
      void Generate_List(void); //This will probably require a unique constructor
  };

  class TTT_Dialog : public Game::BaseDialog
  {
    public:
      TTT_Dialog(std::vector<Game::Player>& Client_List);
      //Game::Player Game::PlayerSelect //Base Implementation
      //Game::Player Player_Setup(void); //Base Implementation if used at all?
      //std::string newPlayer_Name,
      //            newPlayer_Ai,
      //            Play_Again,
      //            Round_Winner,
      //            Round_Tie;
  };
}
#endif
