///////////////////////////////////////////////
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
///////////////////////////////////////////////
#include "UserInterface.hpp" //PlaySpace Definition
#include "ArtificialIntelligence.hpp" //AI Definition
#include <vector> //Turns, board, and Player vectors

namespace GamePlay
{
  class Turn
  {
    AI* ai;
    virtual int AI(void);
    virtual int Player(void);
    virtual bool Validate_Input(int input) = 0;
  };

  struct Player
  {
    std::string Name;
    int Score;
    bool CPU;
  };
  
  class Game
  {
    public:
      virtual void Game_Loop(void);
    private:
      int turn_number,
          move;
      enum Pieces{};
      std::vector<int> turns,
                       board;
      std::vector<Player> players;
      UserInterface::PlaySpace* playspace;
      AI* ai;
      Turn* turn;

      virtual bool Round_Over(void);
      virtual bool Round_Won(void) = 0;
      virtual bool Round_Tie(void) = 0;
      virtual void Process_Move(void) = 0;
      virtual void Round_End(void);
      virtual void Play_Again(void);
      virtual void Reset(void) = 0;


  };
}

#endif
