///////////////////////////////////////////////
#ifndef T3PLAYSPACE_HPP
#define T3PLAYSPACE_HPP
///////////////////////////////////////////////
#include "../../engine/GameComponents.hpp" //PlaySpace Implementation
//#include "T3Components.hpp" // Pieces and Locations probably not needed if defined in owning object
#include <string> //Visual Assets
#include <vector> //Cross and Circle vectors

namespace TicTacToe
{
  class TTT_PlaySpace : public Game::PlaySpace
  {
    public:
      TTT_PlaySpace(const Game::Pieces &Pieces, const Game::Locations &Locations);
      //Locations locations;
      //Pieces pieces;
      void Write_Piece(Game::Location location, Game::Piece piece);
      //void Setup_Display(void) BASE IMPLEMENTATION
      //void Print_PlaySpace(void) BASE IMPLEMENTATION
      void New_Game(void); //Called by game reset
      //void Write_UndoRedo(bool un, bool re) BASE IMPLEMENTATION
    protected:
      //size_t height, width;  
      

      void Write_Header(void);
      void Write_Board(void);
      void Clear_Board(void);
      size_t Get_Coordinate(Game::Location location);
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
      void Write_Blank(Game::Location location);
      void Write_Circle(Game::Location location);
      void Write_Cross(Game::Location location);

      TTT_PlaySpace(); //B A N N E D
  };
}
#endif
