///////////////////////////////////////////////
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
///////////////////////////////////////////////
#include "UserInterface.hpp"
#include <vector>

namespace GamePlay
{
  class Game
  {
    public:
      virtual void Game_Loop(void);
    private:
      int turn,
          move;
      enum Pieces{};
      std::vector<int> turns,
                       board;
      //std::vector<Player*> players;
      UserInterface::PlaySpace* playspace;
      //AI* ai;


      virtual bool Round_Won(void);
      virtual void Game_Turn(void);
      virtual void Process_Turn(void);
      virtual void Set_Move(void);
      virtual void Round_End(void);
      virtual void Play_Again(void);
  };
}

#endif
