///////////////////////////////////////////////
#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
///////////////////////////////////////////////
#include <iostream> //Print PlaySpace
#include <string> //PlaySpace strings
#include <vector> //PlaySpace Vectors

namespace UserInterface
{
   class PlaySpace
   {
      public:
         void Write_PlaySpace(void);
         void New_Game(void);
      protected:
         std::string display;
         size_t height, width;

         void Write_Header(void);
         void Write_Board(void);
         void Print_PlaySpace(void);
         void Clear_Board(void);
   };
}
#endif
