#include "UserInterface.h"

namespace UserInterface
{
   void PlaySpace::Write_PlaySpace()
   {
      display.resize(height * width);
      Write_Header();
      this->Write_Board();
      Print_PlaySpace();
   }

   void PlaySpace::Write_Header()
   {
      //REPLACE THIS WHEN PLAYER OBJECTS ARE IMPLEMENTED 
      for(size_t i = 0; i < display.length(); i++)
      {
         display[i] = ' ';
      }

   }

   void PlaySpace::Write_Board()
   {
      display[0] = 'X';
      display[width*height-1] = 'X';
   }

   void PlaySpace::Print_PlaySpace()
   {
      std::string line;
      for(size_t i = 0; i < display.length(); i+= (size_t)width)
      {
         line = display.substr(i, (size_t)width);
         std::cout << line << std::endl;
      }
   }

}
