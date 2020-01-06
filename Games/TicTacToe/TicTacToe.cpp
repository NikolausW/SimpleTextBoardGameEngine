#include "TicTacToe.hpp"

namespace TicTacToe
{
  TTT::TTT(std::vector<Game::Player>& Client_List) : Base(player_count, *pieces, *locations, *gamestate, *playspace, *turn, *dialog, Client_List)
  {
    player_count = 2;
    pieces = new TTT_Pieces;
    locations = new TTT_Locations;
    gamestate = new TTT_GameState;
    dialog = new TTT_Dialog(Client_List);
    playspace = new TTT_PlaySpace(*locations, *pieces); 
    turn = new Game::Turn(Client_List);
  }
}
