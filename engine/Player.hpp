///////////////////////////////////////////////
#ifndef PLAYER_HPP
#define PLAYER_HPP
///////////////////////////////////////////////
#include <string>

namespace GamePlay
{
  struct Player
  {
    std::string Name;
    int Score;
    bool CPU;
  };
}

#endif
