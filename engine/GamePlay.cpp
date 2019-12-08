#include "GamePlay.hpp"

namespace GamePlay
{
  void Game::Game_Loop(void)
  {
    while(!Round_Over())
    {
      playspace->Write_PlaySpace();
      Execute_Turn();      
      Process_Move();
    }
    Round_End();  
  }

  bool Game::Round_Over(void)
  {
    if(Round_Won() || Round_Tie())
    {
      return true;
    }
    return false;  
  }

  int Game::Execute_Turn(void)
  {
    if(players[Player_X_Turn()]->CPU)
    {
      return turn->AI();
    }    
    return turn->Player();
  }

  size_t Game::Player_X_Turn(void)
  {
    return turn_number % num_players;
  }

  void Game::Round_End(void)
  {
    if(Round_Won())
    {
      Player* winner = players[Player_X_Turn()];
      winner->Score++;
      //dialog->Prompt(); WINNER ANNOUNCEMENT
    }
    else
    {
      dialog->Tie();
    }
    std::cout << "Would you like to play again?" << std::endl;
    Play_Again(dialog.YesNo());
  }

  void Game::Play_Again(bool again)
  {
    if(again)
    {
      Reset();
    }    
  }

  Player_Select::Player_Select(int numPlayers)
  {
    for(int i = numPlayers; i > 0; i--)
    {
      
    }
  }
}


