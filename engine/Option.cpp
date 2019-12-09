#include "Option.hpp"

namespace Option
{
  bool Option::Conditional()
  {
    return true;
  }

  YesNo::YesNo(bool YN)
  {
    selection = YN;
    if(selection){Name = "Yes"; Required_Input = "y";}
    else {Name = "No"; Required_Input = "n";}
  }

  bool YesNo::On_Select()
  {
    return selection;
  }

  //PLAYER IMPLEMENTATION GOES HERE

  //MOVE IMPLEMENTATION GOES HERE

  Game::Game(int number, GameCore::Game* game)  
  {
    Required_Input = std::to_string(number);
    selection = game;
  }

  GameCore::Game* Game::On_Select(void)
  {
    return selection;
  }
}
