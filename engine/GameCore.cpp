#include "GameCore.hpp"

namespace Game
{
  Base::Base(void)
  {
    locations = NULL;
    pieces = NULL;
    player_count = 0;
    players.clear();
    gamestate = NULL;
    playspace = NULL;
    turn = NULL;
    dialog = NULL;
  }

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
      Process_Move(turn->AI());
    }    
    Process_Move(turn->Player());
  }

  size_t Base::Player_X_Turn(void)
  {
    return gamestate->turn_number % player_count;
  }

  void Base::Process_Move(Move move)
  {
    std::vector<Move> updates = gamestate->Update(move);

    for(int i = 0; i < updates.size(); i++)
    {
      playspace->Write_Piece(updates[i].piece, updates[i].square);
    }
  }

  void Base::Round_End(void)
  {
    if(gamestate->Round_Won())
    {
      Player* winner = players[Player_X_Turn()];
      winner->score++;
      dialog->Prompt(dialog->Round_Winner.length(), dialog->Round_Winner); 
    }
    else
    {
      dialog->Prompt(dialog->Round_Tie.length(), dialog->Round_Tie);
    }
    dialog->Prompt(dialog->Play_Again.length(), dialog->Play_Again);
    Play_Again(dialog->YesNo->Select().On_Select());
  }

  void Base::Play_Again(bool again) //REFACTOR THIS
  {
    if(again)
    {
      gamestate->Reset();
    }    
  }
}
