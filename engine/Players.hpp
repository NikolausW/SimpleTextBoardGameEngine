///////////////////////////////////////////////
#ifndef PLAYERS_HPP
#define PLAYERS_HPP
///////////////////////////////////////////////
#include <string>

namespace GamePlay
{
  struct Player
  {
    std::string Name;
    int Score;
    bool AI;
  };
}

#endif