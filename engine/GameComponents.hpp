///////////////////////////////////////////////
#ifndef GAMECOMPONENTS_HPP
#define GAMECOMPONENTS_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include <string>
#include <vector>
// Need Randomized libraries here for AI methods

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

  class GameState
  {
    public:
      int turn_number;
      std::vector<Move*> turns; //stores squares played to, this should be change to move/move*, there's no guarntee that turns will always just be an int
      std::vector<const int> board; //current game/board state   Could change this to <int> or whatever format the enum is, but that forces an enum 
      virtual bool Round_Won(void) = 0; // Checks if Round is won
      virtual bool Round_Tie(void) = 0; // Checks if the Round results in a tie
      virtual void Process_Move(Move* move) = 0; // This will parse the move object
      virtual void Reset(void) = 0; // Resets gamestate
  };

  class Move : public Dialog::Option<Game::Move*>
  {
    public:
      Move(int sq); // Constructor
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Move* On_Select(void);
      // Move* selection; 
      int square;  
  };

  class Move_Select : public Dialog::Option_Select<Game::Move*>
  {
    public:
      // virtual Move* Select(void); 
    protected:
      // int Input_Length;
      // std::string User_Input;
      // std::vector<Move> Options;
      virtual void Print_List(void); // intentionally does nothing
      // virtual std::string Generate_Option_String(Move* option); 
      // virtual std::string Take_Input(void);
      // virtual bool Validate_Input(std::string input); 
      // virtual Move* Process_Input(void); 
      virtual void Generate_List(void) = 0; //This may not need to be pure virtual
  };

  class AI
  {
    public:
      virtual Move* Turn(void) = 0; 
    protected:
      virtual Move* Either(Move a, Move b); // Need to implement
      virtual Move* Open_Space(void); // Need to implement
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
      Move_Select* select; // Does this need to be explecitly a Move_Select* ? Could it be an Option_Select*    
      std::string move_prompt,
                  invalid;

    //  virtual void Prompt(size_t width, std::string str);
    //  YesNo_Select* YesNo;
    //  virtual void Clear_Screen(void);
  };

  class Turn
  {
    public:
      Turn(); // Needs to be written 
      AI* ai;
      Turn_Dialog dialog;
      virtual Move* AI(void);
      virtual Move* Player(void);
  };

  class Player : public Dialog::Option<Game::Player*>
  {
    public:
      Player(); //this should never be called, define it so that it calls below constructor with default values
      Player(std::string name, bool ai);
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Player* On_Select(void);
      // Player* selection;
      int score;
      bool CPU;
  };

  class newPlayer : public Player
  {
    public:
      newPlayer();
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Player* On_Select(void);
      // Player* selection;
      // int score
      // bool CPU 
  };

  class Player_Select : Dialog::Option_Select<Game::Player*> 
  {
    public:
      Player_Select(); // Will need paramatized constructor
      //Player* Select(void);
    protected:
      // int Input_Length;
      // std::string User_Input;
      // std::vector<Move> Options;
      std::vector<Player>* masterlist; // This just needs to be a pointer to client list, might need a constructor param
      std::vector<Player*>* currentplayers;
      bool ai;

      // void Print_List(void); 
      // std::string Generate_Option_String(Player* option); 
      // std::string Take_Input(void); 
      // bool Validate_Input(std::string input); 
      // Player* Process_Input(void); 
      //Badly need to break this into smaller chunks
      void Generate_List(void); // takes client player list, adds option to create new player
  };

  class BaseDialog : public Dialog::Base //Dialog::Game
  {
    //Need to include strings for Again Prompt, Round Winner, and Round Tie
    public:
      BaseDialog(void);  
      Player_Select playerselect; 
      std::string newPlayer_Name,
                  newPlayer_Ai,
                  Play_Again,
                  Round_Winner,
                  Round_Tie;
      // virtual void Prompt(size_t width, std::string str);
      // YesNo_Select* YesNo;
      // virtual void Clear_Screen(void);

      virtual std::vector<Player*> Select_Players(int num_players);
      virtual Player* Player_Setup(void); //calls the player constructor returnin a new player object
  };
}
#endif
