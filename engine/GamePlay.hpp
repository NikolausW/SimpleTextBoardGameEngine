///////////////////////////////////////////////
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
///////////////////////////////////////////////
#include "ArtificialIntelligence.hpp" //AI Definition
#include "Dialog.hpp" //GamePlay Dialog Definition
#include "Move.hpp" //Move Definition
#include "Player.hpp" //Player Definition
#include "Turn.hpp" //Turn Definition
#include "UserInterface.hpp" //PlaySpace Definition
#include <vector> //Turns, Board, and Player vectors

namespace GamePlay
{
  class Game
  {
    public:
      virtual void Game_Loop(void);
    private:
      int num_players,
          turn_number,
          move;
      enum Pieces{};
      std::vector<int> turns,
                       board;
      std::vector<Player*> players;
      UserInterface::PlaySpace* playspace;
      AI* ai;
      Turn* turn;
      Dialog::Dialog* dialog;

      virtual bool Round_Over(void);
      virtual bool Round_Won(void) = 0;
      virtual bool Round_Tie(void) = 0;
      virtual int Execute_Turn(void);
      virtual size_t Player_X_Turn(void);
      virtual void Process_Move(void) = 0;
      virtual void Round_End(void);
      virtual void Play_Again(bool again);
      virtual void Reset(void) = 0;
  };
}

#endif
