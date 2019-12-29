#include "GameList.hpp"

namespace Game
{
  Option::Option(std::string gameName, Base* game)  
  {
    Name = gameName;
    selection = game;
  }

  std::vector<Option> PopulateGameList(void)
  {
    //GameList.push_back(Option("Game Name", Game*));
    GameList.push_back(Option("Tic Tac Toe", &TicTacToe::TTT())); // what does this even do?
    return GameList;
  }
}
