///////////////////////////////////////////////
#ifndef T3PLAYSPACE_HPP
#define T3PLAYSPACE_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp" //PlaySpace Implementation
#include <string>
#include <vector>

namespace TicTacToe
{
  class TTT_PlaySpace : public Game::PlaySpace
  {
    public:
      TTT_PlaySpace(); //Constructor
      //virtual void Setup_Display(void) BASE IMPLEMENTATION
      //virtual void Print_PlaySpace(void) BASE IMPLEMENTATION
      virtual void New_game(void); //Called by game reset
      //virtual void Write_UndoRedo(bool un, bool re) BASE IMPLEMENTATION
    protected:
      //size_t height, width;
      //enum Pieces{}
      //enum Locations{} NEED TO POPULATE THIS

      virtual void Write_Header(void);
      virtual void Write_Board(void);
      virtual void Clear_Board(void);
      virtual size_t Get_Coordinate(Locations location);
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
  };
}
#endif
