#include "TTTPlaySpace.h"

namespace UserInterface
{
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

            std::string line;
      for(size_t i = 0; i < display.length(); i+= (size_t)width)
      {
         line = display.substr(i, (size_t)width);
         std::cout << line << std::endl;
      }
   }


   void TicTacToe::Write_Header()
   {
      std::string P1 = "Steve",
                  P2 = "Phil";
      size_t name1_start = 4 - (P1.length() / 2) -1,
             name2_start = 27 - (P2.length() /2) - 1,
             score1_start = (4 - Player1Score.length() / 2) + 33 - 1,
             score2_start = (27 - Player2Score.length() / 2) + 33 - 1;

      display.replace(name1_start, P1.length(), P1);
      display.replace(name2_start, P2.length(), P2);
      display.replace(score1_start, Player1Score.length(), Player1Score);
      display.replace(score2_start, Player2Score.length(), Player2Score);
   }

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
   }

   void TicTacToe::setupCircle()
   {
      circle.resize(3);
      circle[0] = "/ \\";
      circle[1] = " O ";
      circle[2] = "\\  /";
   }

   void TicTacToe::setupCross()
   {
      cross.resize(3);
      cross[0] = "\\ /";
      cross[1] = " X ";
      cross[2] = "/ \\";
   }



}
