#include "T3PlaySpace.hpp"

namespace TicTacToe
{
  TTT_PlaySpace::TTT_PlaySpace(Game::Pieces &Pieces, Game::Locations &Locations) : Game::PlaySpace(Pieces, Locations, height, width)
  {
  //Dimensions of PlaySpace
    height = 15;
    width = 33;

  //Asset Assignment
    locations = &Locations;
    pieces = &Pieces;
  //Visual Asset Assignment
    //Need access to Current Players
    Player1Score = "Score: ";
    Player2Score = "Score: ";
    boardVertical = "|   |";
    boardHorizontal = "---+---+---";
    blank = "   ";
    Setup_Circle();
    Setup_Cross();
    Setup_Display();
  }

  void TTT_PlaySpace::New_Game(void)
  {
    Setup_Display();
  }

  void TTT_PlaySpace::Write_Piece(const int location, const int piece)
  {
    if(piece == pieces->Blank)
    {
      Write_Blank(location);
    }
    else if(piece == pieces->Cross)
    {
      Write_Cross(location);
    }
    else
    {
      Write_Circle(location);
    }
  }

  void TTT_PlaySpace::Write_Header(void)
  {
    //Player1.score append to Player1score
    //Player2.score append to Player2score
    //display.replace(Get_Coordinate(Header_Name1), Name1.length(), Name1);
    //display.replace(Get_Coordinate(Header_Name2), Name2.length(), Name2);
    //display.replace(Get_Coordinate(Header_Score1), Player1Score.length(), Player1Score);
    //display.replace(Get_Coordinate(Header_Score2), Player2Score.length(), Player2Score);
  }

  void TTT_PlaySpace::Write_Board(void) //This could stand to be refactored
  {
    size_t horizontal1 = (6 * width) + 12 - 1,
           horizontal2 = (10 * width) + 12 - 1;

      for(size_t i = 0; i < 11; i++)
      {
        display.replace((3+i) * 33 + 15 - 1, boardVertical.length(), boardVertical);
      }

      display.replace(horizontal1, boardHorizontal.length(), boardHorizontal),
      display.replace(horizontal2, boardHorizontal.length(), boardHorizontal);

      Clear_Board();
  }
  
  size_t TTT_PlaySpace::Get_Coordinate(const int location)
  {/*
    switch(location)
    {
      case locations->Square_One: return (3 * width) + 12 - 1;
      case locations->Square_Two: return (3 * width) + 16 - 1;
      case locations->Square_Three: return (3 * width) + 20 - 1;
      case locations->Square_Four: return (7 * width) + 12 - 1;
      case locations->Square_Five: return (7 * width) + 16 - 1;
      case locations->Square_Six: return (7 * width) + 20 - 1;
      case locations->Square_Seven: return (11 * width) + 12 - 1;
      case locations->Square_Eight: return (11 * width) + 16 - 1;
      case locations->Square_Nine: return (11 * width) + 20 - 1;
      case locations->Undo: return (11 * width) + 26 - 1;
      case locations->Redo: return (10 * width) + 26 - 1;
      case locations->Board_Horizontal1: return (6 * width) + 12 - 1;
      case locations->Board_Horizontal2: return (10 * width) + 12 - 1;
      case locations->Board_Vertical_Start: return (3 * width) + 15 - 1;
      //case Header_Name1: return 4 - (name.length() / 2) - 1;
      //case Header_Name2: return 27 - (name2.length() / 2) - 1;
      //case Header_Score1: return (4 - Player1Score.length() / 2) + width - 1;
      //case Header_Score2: return (27 - Player2Score.length() / 2) + width - 1;
    }*/
  }

  void TTT_PlaySpace::Setup_Circle(void)
  {
    circle.resize(3);
    circle[0] = "/ \\";
    circle[1] = " O ";
    circle[2] = "\\ /";
  }

  void TTT_PlaySpace::Setup_Cross(void)
  {
    cross.resize(3);
    cross[0] = "\\ /";
    cross[1] = " X ";
    cross[2] = "/ \\";
  }

  void TTT_PlaySpace::Write_Blank(const int location)
  {
    size_t coordinate = Get_Coordinate(location);

    display.replace(coordinate, blank.length(), blank);
    //display.replace(coordinate, 1, std::to_string(square)); //need to translate location to a number value
    display.replace(coordinate + width, blank.length(), blank);
    display.replace(coordinate + (width * 2), blank.length(), blank);
  }

  void TTT_PlaySpace::Write_Circle(const int location)
  {
    size_t coordinate = Get_Coordinate(location);

      for(int i = 0; i < 3; i++)
      {
         display.replace(coordinate + (width * i), circle[i].length(), circle[i]);
      }  
  }

  void TTT_PlaySpace::Write_Cross(const int location)
  {
    size_t coordinate = Get_Coordinate(location);

    for(int i = 0; i < 3; i++)
    {
      display.replace(coordinate + (width * i), cross[i].length(), cross[i]);
    }
  }
}
