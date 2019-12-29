#include "GameComponents.hpp"

namespace Game
{
  typedef const int Piece;
  typedef const int Location;
  
  PlaySpace::PlaySpace()
  {
    undo = "Undo:z";
    redo = "Redo:y";
    removeUndoRedo = "      ";
  }

  void PlaySpace::Setup_Display()
  {
    display.resize(height * width); //Sets display size
    display.replace(display.begin(), display.end(), display.length(), ' '); //Fills display with whitespace

    Write_Header();
    Write_Board();
    Print_PlaySpace();
  }

  void PlaySpace::Print_PlaySpace()
  {
    for(size_t i = 0; i < display.length(); i+= (size_t)width)
      {
         std::cout << display.substr(i, (size_t)width) << std::endl;
      }
  }

  void PlaySpace::Write_UndoRedo(bool un, bool re) // LOL THIS IS SO BAD, PLEASE FIX ME
  {
    if(un)
    {
      display.replace(Get_Coordinate(locations->Redo), redo.length(), redo);
    }
    else
    {
      display.replace(Get_Coordinate(locations->Undo), removeUndoRedo.length(), removeUndoRedo);
    } 
  }

  Move::Move(int sq)
  {
    selection = this;
    square = sq;
  }

  void Move_Select::Print_List(void)
  {
    //Do nothing
  }

  Turn_Dialog::Turn_Dialog()
  {
    move_prompt = "Please make your move: ";
    invalid = "Invalid input, try again: ";
  }
  
  Move* Turn::AI(void)
  {
    return ai->Turn();
  }

  Move* Turn::Player(void)
  {
    dialog.Prompt(dialog.move_prompt.length(), dialog.move_prompt);
    return dialog.select->Select();
  }

  Player::Player(std::string name, bool ai)
  {
    Name = name;
    CPU = ai;
    score = 0;
  }

  newPlayer::newPlayer()
  {
    Name = "New Player";
    Required_Input = "0";
    CPU = false;
    score = 0;
    selection = NULL;
  }

  void Player_Select::Generate_List(void)
  {
    Options.push_back(newPlayer()); // Sets New Player as an option 

    for(int i = 0; i < masterlist->size(); i++)
    {
      if(!(!ai && (*masterlist)[i].CPU)) //skip if user is ai and game does not support
      {
        for(int j = 0; j < currentplayers->size(); j++)
        {
          if((*currentplayers)[j]->Name == (*masterlist)[i].Name){break;} //if player name is already active
          if(j >= Options.size() - 1) //if end of list is reached
          {
            Options.push_back((*masterlist)[i]);
          }
        }
      }
    }
  }

  BaseDialog::BaseDialog(void)
  {
    newPlayer_Name = "";
    newPlayer_Ai = "";
    Play_Again = "";
    Round_Winner = "";
    Round_Tie = "";
  }

  std::vector<Player*> BaseDialog::Select_Players(int num_players)
  {
    std::vector<Player*> Current_Players;

    for(int i = 0; i < num_players; i++)
    {
      Player* player = playerselect.Select();
      if(!player)
      {
        player = Player_Setup();
      }
      Current_Players.push_back(player);
    }
    return Current_Players;
  }

  Player* BaseDialog::Player_Setup(void)
  {
    std::string PlayerName;
    bool PlayerAI;
    Prompt(newPlayer_Name.size(), newPlayer_Name);
    std::cin >> PlayerName;
    Prompt(newPlayer_Ai.size(), newPlayer_Ai);
    PlayerAI = YesNo->Select()->On_Select();
    Player player = Player(PlayerName, PlayerAI);
    // Need a way to push this up to the Client
    return &player; 
  }
}
