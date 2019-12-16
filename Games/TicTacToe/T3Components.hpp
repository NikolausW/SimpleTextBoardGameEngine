///////////////////////////////////////////////
#ifndef T3COMPONENTS_HPP
#define T3COMPONENTS_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp"

namespace TicTacToe
{
  class TTT_Move : public Game::Move
  {
    public:
      TTT_Move(int sq);
      //Move* On_Select(void) BASE IMPLEMENATION
      //int square
  };

  class TTT_Move_Select : public Game::Move_Select
  {
    public:
      //Move* Select(void); ??? BASE BASE IMPLEMENTATION???
    protected:
      //void Print_List(void); BASE IMPLEMENTATION
      void Generate_List(void); //This will probably require a unique constructor
  };

  //Base Implementation of Turn_Dialog?

  class TTT_Turn : public Game::Turn
  {
    public:
      TTT_Turn();
      //AI* ai;
      //Game::Turn_Dialog dialog; //Base Implementation
      //Move* AI(void); //Base Implementation
      //Move* Player(void); //Base Implementation 
  };

  class TTT_Dialog : public Game::BaseDialog
  {
    public:
      TTT_Dialog(void);
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
