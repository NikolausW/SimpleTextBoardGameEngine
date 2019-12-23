#include "TicTacToe.hpp"

namespace TicTacToe
{
  TTT::TTT()
  {
    locations = new TTT_Locations;
    pieces = new TTT_Pieces;

    num_players = 2;
    turn_number = 0;
    board.assign(9, pieces->Blank);
    dialog = new TTT_Dialog;
    players = dialog->Select_Players(num_players);
    playspace = new TTT_PlaySpace;
    //Turn = new Game::Turn; //see if it works without this, does base init carry over?
  }

  bool TTT::Round_Won(void)
  {
    if(turn_number > 4)
    {
      int LastMove = turns[turn_number - 1]->square;
      int LastPiece = board[LastMove - 1];

      switch(LastMove)
      {
        case 1:
        case 2: 
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
      }
    } 
  }

  bool TTT::Round_Tie(void)
  {
    // after turn #? check if any of the blanks could result in win
  }

  void TTT::Process_Move(Game::Move* move)
  {
    
  }

  void TTT::Reset(void)
  {

  }
}