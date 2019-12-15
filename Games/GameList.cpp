#include "GameList.hpp"

namespace Game
{
  Option::Option(int number, Base* game)  
  {
    Required_Input = std::to_string(number);
    selection = game;
  }

  Base* Option::On_Select(void)
  {
    return selection;
  }
}
