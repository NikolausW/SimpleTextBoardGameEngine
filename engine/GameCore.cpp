#include "GameCore.hpp"

namespace GameCore
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
      Option::Player* winner = players[Player_X_Turn()];
      winner->score++;
      //dialog->Prompt(); WINNER ANNOUNCEMENT
    }
    else
    {
      //dialog prompt tie CATS GAME
    }
    std::cout << "Would you like to play again?" << std::endl; //Change this to a prompt
    //Play_Again(dialog.YesNo()); Need to figure out reference to YesNo
  }

  void Game::Play_Again(bool again)
  {
    if(again)
    {
      Reset();
    }    
  }


  //PLAYSPACE GOES HERE

  int Turn::AI(void)
  {
    return ai->Turn();
  }

  int Turn::Player(void)
  {
    //return dialog->Receive_Input()
  }
}
