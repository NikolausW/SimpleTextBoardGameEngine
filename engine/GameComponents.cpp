#include "GameComponents.hpp"

namespace Game
{
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

  void PlaySpace::Write_UndoRedo(bool un, bool re)
  {
    if(un){display.replace(Get_Coordinate(Redo), redo.length(), redo);}
    else{display.replace(Get_Coordinate(Undo), removeUndoRedo.length(), removeUndoRedo);} 
  }

  Move::Move(int sq)
  {
    square = sq;
  }

  Move* Move::On_Select()
  {
    return this;
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

  Player* Player::On_Select()
  {
    return this;
  }

  newPlayer::newPlayer()
  {
    Name = "New Player";
    Required_Input = "0";
    CPU = true;
    score = 0;
  }

  Player* newPlayer::On_Select()
  { 
    Player* empty;
    return empty;
  }

  void Player_Select::Generate_List(void)
  {
    Options.push_back(newPlayer());

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




}
