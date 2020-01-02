#include "TicTacToe.hpp"

namespace TicTacToe
{
  TTT::TTT(std::vector<Game::Player>& GlobalPlayerList)
  {
    //Sets the Locations and Pieces
    locations = new TTT_Locations;
    pieces = new TTT_Pieces;
    player_count = 2;

    //Sets dialog for Player vector setup
    dialog = new TTT_Dialog(Game::Player_Select(true, GlobalPlayerList));
    players.clear();
    dialog->Select_Players(player_count);

    gamestate = new TTT_GameState(*pieces, *locations, (size_t)9, true);

    playspace = new TTT_PlaySpace(*pieces, *locations);

    turn = new Game::Turn(TTT_AI(*gamestate), TTT_Dialog(TTT_Move_Select()));
  }
}