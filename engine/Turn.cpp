#include "Turn.hpp"

namespace GamePlay
{
int Turn::AI(void)
  {
    return ai->Turn();
  }

  int Turn::Player(void)
  {
    //return dialog->Receive_Input()
  }
}
