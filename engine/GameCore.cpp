#include "GameCore.hpp"

namespace Game
{
  void Base::Game_Loop(void)
  {
    while(!Round_Over())
    {
      playspace->Print_PlaySpace();
      Execute_Turn();      
    }
    Round_End();  
  }

  bool Base::Round_Over(void)
  {
    if(gamestate->Round_Won() || gamestate->Round_Tie())
    {
      return true;
    }
    return false;  
  }

  void Base::Execute_Turn() 
  {
    if(players[Player_X_Turn()]->CPU)
    {
      gamestate->Process_Move(turn->AI());
    }    
    gamestate->Process_Move(turn->Player());
  }

  size_t Base::Player_X_Turn(void)
  {
    return gamestate->turn_number % num_players;
  }

  void Base::Process_Move(Move* move)
  {
    //parse the move and do something with it
  }

  void Base::Round_End(void)
  {
    if(gamestate->Round_Won())
    {
      Player* winner = players[Player_X_Turn()];
      winner->score++;
      //dialog->Prompt(); WINNER ANNOUNCEMENT
    }
    else
    {
      //dialog prompt tie CATS GAME
    }
    //std::cout << "Would you like to play again?" << std::endl; //Change this to a prompt
    //Play_Again(dialog.YesNo()); Need to figure out reference to YesNo
  }

  void Base::Play_Again(bool again) //REFACTOR THIS
  {
    if(again)
    {
      gamestate->Reset();
    }    
  }
}
