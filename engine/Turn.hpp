///////////////////////////////////////////////
#ifndef TURN_HPP
#define TURN_HPP
///////////////////////////////////////////////
#include "ArtificialIntelligence.hpp"
#include "Dialog.hpp"

namespace GamePlay
{
  class Turn
  {
    public:
      AI* ai;
      Dialog::Dialog* dialog; //Place Holder plz fix
      
      virtual int AI(void);
      virtual int Player(void);
      virtual bool Valid_Input(char input) = 0; //What does this do?
  };
}

#endif
