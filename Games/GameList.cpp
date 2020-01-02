#include "GameList.hpp"

namespace Game
{
  Option::Option(std::string GameName, Games GameType)
  {
    game = GameType;
    Name = GameName;
  }

  void Option::On_Select(GameData& option)
  {
    switch(game)
    {
      case TicTacToe: option = new GameData {}
      // Your case here
    } 
  }

  void PopulateGameList(std::vector<Game::Option> gamelist)
  {
    //GameList.push_back(Option("Game Name"));
  }


}
