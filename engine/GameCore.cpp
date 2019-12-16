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
    if(Round_Won() || Round_Tie())
    {
      return true;
    }
    return false;  
  }

  void Base::Execute_Turn()  // this should return a move
  {
    if(players[Player_X_Turn()]->CPU)
    {
      Process_Move(turn->AI());
    }    
    Process_Move(turn->Player());
  }

  size_t Base::Player_X_Turn(void)
  {
    return turn_number % num_players;
  }

  void Base::Round_End(void)
  {
    if(Round_Won())
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

  void Base::Play_Again(bool again)
  {
    if(again)
    {
      Reset();
    }    
  }
}
