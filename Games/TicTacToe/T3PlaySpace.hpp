///////////////////////////////////////////////
#ifndef T3PLAYSPACE_HPP
#define T3PLAYSPACE_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp" //PlaySpace Implementation
#include <string> //Visual Assets
#include <vector> //Cross and Circle vectors

namespace TicTacToe
{
  class TTT_PlaySpace : public Game::PlaySpace
  {
    public:
      TTT_PlaySpace(); //Constructor
      //virtual void Setup_Display(void) BASE IMPLEMENTATION
      //virtual void Print_PlaySpace(void) BASE IMPLEMENTATION
      void New_Game(void); //Called by game reset
      //virtual void Write_UndoRedo(bool un, bool re) BASE IMPLEMENTATION
      void Write_Piece(TTT_PlaySpace::Locations location, TTT_PlaySpace::Pieces piece);
    protected:
      //size_t height, width;  
      enum Locations{Undo, Redo,
                     Board_Horizontal1, Board_Horizontal2,
                     Board_Vertical_Start,
                     Header_Name1, Header_Name2,
                     Header_Score1, Header_Score2,
                     One, Two, Three, Four, Five,
                     Six, Seven, Eight, Nine};
      enum Pieces{Blank, Circle, Cross};

      void Write_Header(void);
      void Write_Board(void);
      void Clear_Board(void);
      size_t Get_Coordinate(Locations location);
    private:
      //visual Assets
      std::string Player1Score,
                  Player2Score,
                  boardVertical,
                  boardHorizontal,
                  blank;
      std::vector<std::string> circle,
                               cross;

      //Unique Methods
      void Setup_Circle(void);
      void Setup_Cross(void);
      void Write_Blank(Locations location);
      void Write_Circle(Locations location);
      void Write_Cross(Locations location);
  };
}
#endif
