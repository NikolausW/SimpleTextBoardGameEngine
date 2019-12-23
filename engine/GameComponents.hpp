///////////////////////////////////////////////
#ifndef GAMECOMPONENTS_HPP
#define GAMECOMPONENTS_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include <string>
#include <vector>

namespace Game
{
  struct Locations
  {
    public: // Silly because structs by default are public
      const int Undo = 1000,
                Redo = 1001;
      virtual ~Locations() = 0;
      //Should all games be forced to include Header components?
  };

  struct Pieces
  {
    public: //Silly because structs by default are public
      const int Blank = 0;
      virtual ~Pieces() = 0;
  };

  class Move : public Dialog::Option
  {
    public:
      Move(int sq);
      Move* On_Select(); //Turn_Select
      int square;  
  };

  class Move_Select : public Dialog::Option_Select
  {
    public:
      virtual Move* Select(void);
    protected:
      virtual void Print_List(void);
      virtual void Generate_List(void) = 0; //This may not need to be pure virtual
  };

  class AI
  {
    public:
      virtual Move* Turn(void) = 0; 
    protected:
      virtual Move* Either(Move a, Move b); //Need to implement
      virtual Move* Open_Space(void); //Need to implement
  };

  class PlaySpace 
  {
    
    public:
      PlaySpace();
      Pieces* pieces;
      Locations* locations;
      virtual void Setup_Display(void); // Writes Header and Board and then Prints Playspace
      virtual void Print_PlaySpace(void);
      virtual void New_Game(void) = 0; //This might not need to exist?
      virtual void Write_UndoRedo(bool un, bool re); //Writes or clears undo redo instructions
      virtual void Write_Piece(const int location, const int piece) = 0;
    protected:
      std::string display,
                  redo,
                  undo,
                  removeUndoRedo;
      size_t height, width;
      

      virtual void Write_Header(void) = 0;
      virtual void Write_Board(void) = 0;
      virtual void Clear_Board(void) = 0;
      virtual size_t Get_Coordinate(const int location) = 0;
  };

  class Turn_Dialog : public Dialog::Base
  {
    public:
      Turn_Dialog();
      Move_Select* select;      
      std::string move_prompt,
                  invalid;
  };

  class Turn
  {
    public:
      Turn();
      AI* ai;
      Turn_Dialog dialog;
      virtual Move* AI(void);
      virtual Move* Player(void);
  };

  class Player : public Dialog::Option 
  {
    public:
      Player(); //this should never be called
      Player(std::string name, bool ai);
      Player* On_Select();
      int score;
      bool CPU;
  };

  class newPlayer : public Player //This should probably be a singleton
  {
    public:
      newPlayer();
      Player* On_Select();
  };

  class Player_Select : Dialog::Option_Select // This should be a singleton
  {
    public:
      Player_Select();
      virtual Player* Select(void);
    protected:
      std::vector<Player>* masterlist;
      std::vector<Player*>* currentplayers;
      bool ai;
      //Badly need to break this into smaller chunks
      void Generate_List(void); // takes client player list, adds option to create new player
  };

  class BaseDialog : public Dialog::Base //Dialog::Game
  {
    //Need to include strings for Again Prompt, Round Winner, and Round Tie
    public:
      BaseDialog(void);  
      Player_Select playerselect; 
      virtual std::vector<Player*> Select_Players(int num_players);
      virtual Player* Player_Setup(void); //calls the player constructor returnin a new player object
      std::string newPlayer_Name,
                  newPlayer_Ai,
                  Play_Again,
                  Round_Winner,
                  Round_Tie;
  };
}
#endif
