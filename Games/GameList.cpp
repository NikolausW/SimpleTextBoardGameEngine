#include "GameList.hpp"

namespace Game
{
  Option::Option(std::string gameName, Base* game)  
  {
    Name = gameName;
    selection = game;
  }

  Base* Option::On_Select(void)
  {
    return selection;
  }

  std::vector<Option> PopulateGameList(void)
  {
    //GameList.push_back(Option("Game Name", Game*));

    return GameList;
  }
}
