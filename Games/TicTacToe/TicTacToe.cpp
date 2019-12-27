#include "TicTacToe.hpp"

namespace TicTacToe
{
  TTT::TTT()
  {
    locations = new TTT_Locations;
    pieces = new TTT_Pieces;
    num_players = 2;
    dialog = new TTT_Dialog;
    players = dialog->Select_Players(num_players);
    playspace = new TTT_PlaySpace;
    //Turn = new Game::Turn; //see if it works without this, does base init carry over?
  }

  void TTT::Process_Move(Game::Move* move)
  {
    
  }
}