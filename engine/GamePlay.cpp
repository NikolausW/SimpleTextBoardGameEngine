#include "GamePlay.hpp"

namespace GamePlay
{
  void Game::Game_Loop(void)
  {
    while(!Round_Over())
    {
      //playspace->Write_PlaySpace();
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
      dialog->Round_Winner(winner->Name);
    }
    else
    {
      dialog->Tie();
    }
    Play_Again(dialog->Again_Prompt());
  }

  void Game::Play_Again(bool again)
  {
    if(again)
    {
      Reset();
    }
    else
    {
      //delete this;
    }    
  }
}


