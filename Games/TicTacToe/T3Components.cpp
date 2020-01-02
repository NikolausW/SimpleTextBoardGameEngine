#include "T3Components.hpp"

namespace TicTacToe
{
  TTT_GameState::TTT_GameState(const Game::Pieces &Pieces, const Game::Locations &Locations, size_t BoardSize, bool ai) : Game::GameState(Pieces, Locations, BoardSize, ai)
  {
    Reset();  
  }

  bool TTT_GameState::Round_Won()
  {
    if(turn_number > 4)
    {
      int LastMove = turns[turn_number - 1].square;
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

  bool TTT_GameState::Round_Tie()
  {
    // after turn #5? check if any of the blanks could result in win
    // go through each square of board check if available rows result in !unwinnable
  }


  void TTT_GameState::Reset(void)
  {
    turn_number = 0;
    turns.clear();
    board.assign(9, pieces->Blank);
  }

  void TTT_Move_Select::Generate_List()
  {
    // How should I go about generating a list of possible moves?
  }

  TTT_Dialog::TTT_Dialog(Game::Player_Select& PlayerSelect) : Game::BaseDialog(PlayerSelect)
  {
    newPlayer_Name = "";
    newPlayer_Ai = "";
    Play_Again = "";
    Round_Winner = "";
    Round_Tie = "";
  }
}
