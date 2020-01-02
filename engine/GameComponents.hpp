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
  typedef int Piece;
  typedef int Location;

  struct Locations
  {
    public: // Silly because structs by default are public
      const static Location Undo = 1000,
                            Redo = 1001;
      virtual ~Locations() = 0;
      //Should all games be forced to include Header components?
  };

  struct Pieces
  {
    public: //Silly because structs by default are public
      const static Piece Blank = 0;
      virtual ~Pieces() = 0;
  };

  class Move : public Dialog::Option<Game::Move*>
  {
    public:
      Move(Location sq, Piece pc, std::string Required_Input); // Constructor
      // std::string name,
      //             required_input;
      // bool Conditional(void);
      Move* On_Select(void);
      Move* selection; 
      Location square;
      Piece piece;
  };

  class Move_Select : public Dialog::Option_Select<Game::Move>
  {
    public:
      virtual Move Select(void); 
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

  class GameState
  {
    public:
      GameState(const Pieces &Pieces, const Locations &Locations, size_t BoardSize, bool ai);
      int turn_number;
      bool Active_AI; // If a current player is AI THIS SHOULD LIKELY BE CONST
      virtual std::vector<Move> Update(Move* move); // Updates Gamestate
      virtual bool Round_Won(void) = 0; // Checks if Round is won
      virtual bool Round_Tie(void) = 0; // Checks if the Round results in a tie
      virtual void Reset(void) = 0; // Resets gamestate
    protected:
      const Locations* locations;
      const Pieces* pieces;

      virtual void Setup_Board(void); // By default does nothing
      virtual std::vector<Move> Undo(void);
      virtual std::vector<Move> Redo(void);
      std::vector<Move> turns; // Effectively turn history
      std::vector<Piece> board; //current game/board state
    private:
      GameState(); // B A N N E D 
  };

  class AI
  {
    public:
      //AI(Gamestate& GameState); // Need to pass in the proper gamestate
      virtual Move Turn(void) = 0; 
    protected:
      //Gamestate* gamestate; // For AI to reference the current gamestate
      virtual Move Either(Move& a, Move& b); // Need to implement
      virtual Move Open_Space(void); // Need to implement
  };

  class PlaySpace 
  {  
    public:
      PlaySpace(const Pieces &Pieces, const Locations &Locations, size_t Width, size_t Height);
      const Pieces* pieces;
      const Locations* locations;
      void Setup_Display(void); // Writes Header and Board and then Prints Playspace
      virtual void Print_PlaySpace(void);
      virtual void New_Game(void) = 0; //This might not need to exist?
      virtual void Write_UndoRedo(bool un, bool re); //Writes or clears undo redo instructions
      virtual void Write_Piece(Piece piece, Location location) = 0; // Could make this abstract enough to not be pure virtual
    protected:
      std::string display,
                  redo,
                  undo,
                  removeUndoRedo;
      size_t height, width;
      

      virtual void Write_Header(void) = 0;
      virtual void Write_Board(void) = 0;
      virtual void Clear_Board(void) = 0;
      virtual size_t Get_Coordinate(const Location location) = 0;
    private:
      PlaySpace(); // B A N N E D
  };

  class Turn_Dialog : public Dialog::Base
  {
    public:
      Turn_Dialog(Move_Select &move_select);
      Move_Select* select;    
      std::string move_prompt,
                  invalid;

    //  virtual void Prompt(size_t width, std::string str);
    //  YesNo_Select* YesNo;
    //  virtual void Clear_Screen(void);
    private:
      Turn_Dialog(); // B A N N E D
  };

  class Turn
  {
    public:
      Turn(AI& AI, Turn_Dialog& Dialog); // Needs to be written 
      AI* ai;
      Turn_Dialog* dialog;
      virtual Move AI(void);
      virtual Move Player(void);
    private:
      Turn(); // B A N N E D
  };

  class Player : public Dialog::Option<Player*>
  {
    public:
      Player(std::string Name, bool ai);
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Player* On_Select(void);
      // Player* selection;
      int score;
      bool CPU;
    private:
      Player(); // B A N N E D
      friend class New_Player; // Allows for newPlayer to have default constructor
  };

  class New_Player : public Player
  {
    public:
      New_Player();
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Player* On_Select(void);
      // Player* selection;
      // int score
      // bool CPU 
  };

  class Player_Select : Dialog::Option_Select<Player> 
  {
    public:
      Player_Select(bool ai, std::vector<Player>& ClientList);
      Player Select();
      virtual Player* Add_Player(Player newPlayer);
    protected:
      bool ai_available; // AI available for current game
      // int Input_Length;
      // std::string User_Input;
      // std::vector<Move> Options;
      std::vector<Player>* masterlist; // This just needs to be a pointer to client list
      std::vector<Player*>* currentplayers;

      // void Print_List(void); 
      // std::string Generate_Option_String(Player* option); 
      // std::string Take_Input(void); 
      // bool Validate_Input(std::string input); 
      // Player* Process_Input(void); 
      //Badly need to break this into smaller chunks
      void Generate_List(void); // takes client player list, adds option to create new player
  };

  class BaseDialog : protected Dialog::Base 
  {
    //Need to include strings for Again Prompt, Round Winner, and Round Tie
    public:
      BaseDialog(Player_Select& PlayerSelect);  
      Player_Select* playerselect;
      std::vector<Player>* masterlist;
      std::vector<Player*>* currentplayers;
      std::string newPlayer_Name,
                  newPlayer_Ai,
                  Play_Again,
                  Round_Winner,
                  Round_Tie;

      virtual void Select_Players(int num_players);
      Player* Player_Setup(void); //calls the player constructor returnin a new player object
      // virtual void Prompt(size_t width, std::string str);
      // YesNo_Select* YesNo;
      // virtual void Clear_Screen(void);
    private:
      BaseDialog();
  };
}
#endif
