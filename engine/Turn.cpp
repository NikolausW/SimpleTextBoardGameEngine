#include "Turn.hpp"

namespace GamePlay
{
int Turn::AI(void)
  {
    return ai->Turn();
  }

  int Turn::Player(void)
  {
     char input = dialog->Turn_Prompt(false);
     while(!Valid_Input(input))
     {
       input = dialog->Turn_Prompt(true);
     }
     return input;
  }
}
