///////////////////////////////////////////////
#ifndef GAMECOMPONENTS_HPP
#define GAMECOMPONENTS_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include <string>
#include <vector>

namespace Game
{
  class AI
  {
    public:
      virtual Move Turn(void) = 0; 
  };

  class PlaySpace 
  {
    public:
      virtual void Write_PlaySpace(void);
      virtual void New_Game(void);
    protected:
      std::string display,
                  redo,
                  undo,
                  removeUndoRedo;
      size_t height, width;
      enum Pieces{};
      enum Locations{Redo, Undo};

      virtual void Write_Header(void) = 0;
      virtual void Write_Board(void) = 0;
      virtual void Print_PlaySpace(void);
      virtual void Clear_Board(void) = 0;
      virtual void Write_Piece(size_t coordinate, Pieces piece) = 0;
      virtual void Write_UndoRedo(bool un, bool re);
      virtual size_t Get_Coordinate(Locations location) = 0;
  };

  class Move_Select : public Dialog::Option_Select
  {
    //need to override either Select or PrintList to remove/replace output
  };

  class Move : public Dialog::Option
  {
    Move* On_Select(int square); //Turn_Select
    int square;  
  };

  class Turn_Dialog : public Dialog::Base
  {
    public:
      Turn_Dialog();
    private:
      Move_Select* select;
      //Strings go here

  };

  class Turn
  {
    public:
      AI* ai;
      Turn_Dialog dialog;
      
      virtual Move AI(void);
      virtual Move Player(void);
  };


  class Player : public Dialog::Option //What the actual fuck is wrong with this implementation?
  {
    public:
      void On_Select(std::vector<Player*> players); //Player Select, this should return a list of players, not take one
      int score;
      bool CPU;
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

  class BaseDialog : public Dialog::Base //Dialog::Game
  {
    //Need to include strings for Turn and Again Prompt, Round Winner, and Round Tie
    public:  
      Player PlayerSelect; 
      //virtual void Player_Setup(void); //calls the player constructor returnin a new player object
  };
}
#endif
