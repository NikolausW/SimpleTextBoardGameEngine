///////////////////////////////////////////////
#ifndef TTTPLAYSPACE_H
#define TTTPLAYSPACE_H
///////////////////////////////////////////////
#include "../../engine/UserInterface.h"

namespace UserInterface
{
   class TicTacToe : public PlaySpace
   {
      public:
         TicTacToe();
         virtual void Print_PlaySpace(void);
      protected:
         virtual void Write_Board(void);
         virtual void Write_Header(void);
      private:
         //Visual Assets
         std::string Player1Score, 
                     Player2Score,
                     undo,
                     redo, 
                     removeUndoRedo,
                     boardVertical,
                     boardHorizontal,
                     blank;
         std::vector<std::string> circle,
                                  cross;
         //Unique Methods
         void setupCircle(void);
         void setupCross(void); 
         void Clear_Board(void);
         void Write_Blank(int square);
         void Write_Cross(int square);
         void Write_Circle(int square);
         void Write_Redo(bool available);
         void Write_Undo(bool available);
         size_t Get_Coordinate(int square);
   };
}
#endif