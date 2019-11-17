#include "TTTPlaySpace.hpp"

namespace UserInterface
{
  /****************************************************************************************
   Description : Creates a TicTacToe PlaySpace, initializing all needed components 
   Returns     : A fully initialized TicTacToe PlaySpace
  ****************************************************************************************/   
  TicTacToe::TicTacToe()
   {
      //Dimensions of PlaySpace   
      height = 15;
      width = 33;
      //Asset assignment
      Player1Score = "Score:";
      Player2Score = "Score:";
      undo = "Undo:z";
      redo = "Redo:y";
      removeUndoRedo = "      ";
      boardVertical = "|   |";
      boardHorizontal = "---+---+---";
      blank = "   ";
      setupCircle();
      setupCross();

      //Display Setup
      display.resize(height * width); //Sets display size
      display.replace(display.begin(), display.end(), display.length(), ' '); //Fills display with whitespace
      
      Write_Header();
      Write_Board();   
      Print_PlaySpace();
   }

    /****************************************************************************************
    Description : Splits display into substrings the size desired output width and then
                  prints them out one by one.
    ****************************************************************************************/
   void TicTacToe::Print_PlaySpace()
   {
      std::string line;
      for(size_t i = 0; i < display.length(); i+= (size_t)width)
      {
         line = display.substr(i, (size_t)width);
         std::cout << line << std::endl;
      }
   }

     /****************************************************************************************
     Description : Writes the first two lines of display which show the player names and 
                 their scores
     ****************************************************************************************/
   void TicTacToe::Write_Header()
   {
      std::string P1 = "Steve",
                  P2 = "Phil";
      size_t name1_start = 4 - (P1.length() / 2) -1,
             name2_start = 27 - (P2.length() / 2) - 1,
             score1_start = (4 - Player1Score.length() / 2) + 33 - 1,
             score2_start = (27 - Player2Score.length() / 2) + 33 - 1;

      display.replace(name1_start, P1.length(), P1);
      display.replace(name2_start, P2.length(), P2);
      display.replace(score1_start, Player1Score.length(), Player1Score);
      display.replace(score2_start, Player2Score.length(), Player2Score);
   }

     /****************************************************************************************
     Description : Writes the Tic Tac Toe board to display and then writes Blanks to all
                 squares
     ****************************************************************************************/
   void TicTacToe::Write_Board()
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

     /****************************************************************************************
     Description : Sets up the circle vector with the 3 strings that make up a circle piece
     ****************************************************************************************/
   void TicTacToe::setupCircle()
   {
      circle.resize(3);
      circle[0] = "/ \\";
      circle[1] = " O ";
      circle[2] = "\\ /";
   }

     /****************************************************************************************
     Description : Sets up the cross vector with the 3 strings that make up a cross piece
     ****************************************************************************************/
   void TicTacToe::setupCross()
   {
      cross.resize(3);
      cross[0] = "\\ /";
      cross[1] = " X ";
      cross[2] = "/ \\";
   }

     /****************************************************************************************
     Description : Writes a Blank piece to every square on the Tic Tac Toe board
     ****************************************************************************************/
   void TicTacToe::Clear_Board()
   {
      for(int i = 1; i <= 9; i++)
      {
         Write_Blank(i);
      }
   }

     /****************************************************************************************
     Parameters  : int square - the Tic Tac Toe board square to be written to
     Description : Places the square number in the upper left of the provided square and then 
                 fills the rest of the square with whitespace
     ****************************************************************************************/
   void TicTacToe::Write_Blank(int square)
   {
      size_t coordinate = Get_Coordinate(square);

      display.replace(coordinate, blank.length(), blank);
      display.replace(coordinate, 1, std::to_string(square));
      display.replace(coordinate + width, blank.length(), blank);
      display.replace(coordinate + (width * 2), blank.length(), blank);
   }

     /****************************************************************************************
     Parameters  : int square - the Tic Tac Toe board square to be written to
     Description : Writes the elements of cross to the given square of the Tic Tac Toe board
     ****************************************************************************************/   
   void TicTacToe::Write_Cross(int square)
   {
      size_t coordinate = Get_Coordinate(square);

      for(int i = 0; i < 3; i++)
      {
         display.replace(coordinate + (width * i), cross[i].length(), cross[i]);
      }
   }

     /****************************************************************************************
     Parameters  : int square - the Tic Tac Toe board square to be written to
     Description : Writes the elements of circle to the given square of the Tic Tac Toe board
     ****************************************************************************************/   
   void TicTacToe::Write_Circle(int square)
   {
      size_t coordinate = Get_Coordinate(square);

      for(int i = 0; i < 3; i++)
      {
         display.replace(coordinate + (width * i), circle[i].length(), circle[i]);
      }  
   }

     /****************************************************************************************
     Parameters  : bool available - If the redo option is available
     Description : If available writes redo to display, else writes whitespace to the location
     ****************************************************************************************/
   void TicTacToe::Write_Redo(bool available)
   {
      size_t coordinate = (10 * width) + 26 - 1;

      if(available)
      {
         display.replace(coordinate, redo.length(), redo);
      }
      else
      {
         display.replace(coordinate, removeUndoRedo.length(), removeUndoRedo);
      }    
   }

     /****************************************************************************************
     Parameters  : bool available - If the undo option is available
     Description : If available writes undo to display, else writes whitespace to the location
     ****************************************************************************************/
   void TicTacToe::Write_Undo(bool available)
   {
      size_t coordinate = (11 * width) + 26 - 1;

      if(available)
      {
         display.replace(coordinate, undo.length(), undo);
      }
      else
      {
         display.replace(coordinate, removeUndoRedo.length(), removeUndoRedo);
      }
   }

     /****************************************************************************************
     Parameters  : int square - the Tic Tac Toe board square being requested
     Description : Given square calculates the coordinate of said square in display
   Formula     : ((Row - 1) * width) + column - 1
     Returns     : size_t coordinate - the location within display for the given square
     ****************************************************************************************/
   size_t TicTacToe::Get_Coordinate(int square)
   {
      switch(square)
      {
         case 1: return (3 * width) + 12 - 1;
         case 2: return (3 * width) + 16 - 1;
         case 3: return (3 * width) + 20 - 1;
         case 4: return (7 * width) + 12 - 1;
         case 5: return (7 * width) + 16 - 1;
         case 6: return (7 * width) + 20 - 1;
         case 7: return (11 * width) + 12 - 1;
         case 8: return (11 * width) + 16 - 1;
         case 9: return (11 * width) + 20 - 1; 
      }
      abort();
   }

}
