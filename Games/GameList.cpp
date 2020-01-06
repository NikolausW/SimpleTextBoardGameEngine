#include "GameList.hpp"

namespace Game
{
  Option::Option(std::string Game_Name, Games Game_Type, std::vector<Game::Player>& Client_List) : Dialog::Option<Base*>(selection, Game_Name, required_input)
  {
    game = Game_Type;
    required_input = std::to_string(game);
    client_list = &Client_List;
    selection = NULL;
  }

  Base* Option::On_Select(void)
  {
    switch(game)
    {
      case TicTacToe: selection = new TicTacToe::TTT();
      // case YourGame: selection = new YourGame::Core();
    } 
    return selection;
  }

  void PopulateGameList(std::vector<Game::Option>& Game_List, std::vector<Player>& Client_List)
  {
    //GameList.push_back(Option("Game Name"));
    Game_List.push_back(Option("Tic Tac Toe", TicTacToe, Client_List));

  }


}
