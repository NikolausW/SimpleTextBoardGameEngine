///////////////////////////////////////////////
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
///////////////////////////////////////////////
#include "ArtificialIntelligence.hpp" //AI Definition
#include "Dialog.hpp" //GamePlay Dialog Definition
#include "Move.hpp" //Move Definition
//#include "Player.hpp" //Player Definition
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
          move; // probably won't need this variable
      enum Pieces{};
      std::vector<int> turns,
                       board;
      std::vector<Player*> players;
      UserInterface::PlaySpace* playspace;
      AI* ai;
      Turn* turn;
      GameDialog dialog;

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

  class GameDialog : public Dialog::Dialog
  {
    //Need to include strings for Turn and Again Prompt, Round Winner, and Round Tie
    public:  
      Player_Select PlayerSelect; 
      virtual void Player_Setup(GamePlay::Player* newPlayer); //calls the player constructor returning a new player object
  };

  class Player_Select : Dialog::Option_Select
  {
    public:
      Player_Select(int numPlayers); //will call option select numPlayers number of times
    protected:
      void Generate_List(void);
    private:
      int Num_Players;
  };

  class Player : public Dialog::Option
  {
    public:
      void On_Select(std::vector<GamePlay::Player*>* players); //Player Select
      std::string Name;
      int score;
      bool CPU;
  };

  class Move : public Dialog::Option
  {
    GamePlay::Move* On_Select(int square); //Turn_Select
    int square;  
  };

  class Move_Select : public Dialog::Option_Select
  {
    //need to override either Select or PrintList to remove/replace output
  };  
}

#endif
