#include "T3Components.hpp"

namespace TicTacToe
{
  TTT_GameState::TTT_GameState() : Game::GameState(*pieces, *locations, 9, NULL)
  {
    pieces = new TTT_Pieces();
    locations = new TTT_Locations();
    size_t Boardsize = 9;
    Game::AI* ai = NULL;
    Reset();  
  }

  bool TTT_GameState::Round_Won()
  {
    if(turn_number > 4)
    {
      int LastMove = turns[turn_number - 1].square;
      int LastPiece = board[LastMove - 1];

      
      
    } 
  }

  bool TTT_GameState::Round_Tie()
  {
    if(turn_number > 5)
    {
      for(const auto square: board)
      {
        if(square == pieces->Blank)
        {
          if(Square_Status(square) != Unwinnable)
          {
            return false;
          }
        }
      }
      return true;
    }
    return false;
  }


  void TTT_GameState::Reset(void)
  {
    turn_number = 0;
    turns.clear();
    board.assign(9, pieces->Blank);
  }

  TTT_GameState::Status TTT_GameState::Square_Status(const Game::Location square)
  {
    int width = 3,
        row = (square - 1) / width + 1,
        column = (square - 1) % width + 1;

    Row_Status(row);
    Column_Status(column); 

  }

  TTT_Move_Select::TTT_Move_Select() : Game::Move_Select(input_length)
  {
    input_length = 1;
  }

  void TTT_Move_Select::Generate_List()
  {
    // How should I go about generating a list of possible moves?
  }

  TTT_Dialog::TTT_Dialog(std::vector<Game::Player>& Client_List) : Game::BaseDialog(true, Client_List)
  {
    newPlayer_Name = "";
    newPlayer_Ai = "";
    Play_Again = "";
    Round_Winner = "";
    Round_Tie = "";
  }
}
