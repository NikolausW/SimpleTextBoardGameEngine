#include "GameComponents.hpp"

namespace Game
{
  Move::Move(Location Square, Piece Piece, std::string Required_Input) : Dialog::Option<Move*>(this, " ", Required_Input)
  {
    name = " ";
    required_input = Required_Input;
    selection = this;
    piece = Piece;
    square = Square;
  }

  void Move_Select::Print_List(void)
  {
    //Do nothing
  }

  GameState::GameState(const Pieces &Pieces, const Locations &Locations, size_t BoardSize, bool ai)
  {
    Active_AI = ai;
    pieces = &Pieces;
    locations = &Locations;
    turns.clear();
    board.resize(BoardSize, pieces->Blank);
    turn_number = 0;

    Setup_Board();
  }

  std::vector<Move> GameState::Update(Move* move)
  {
    std::vector<Move> updates;

    if(move->piece)
    {
      board.erase(board.begin() + (move->square - 1));
      board.insert(board.begin() + (move->square - 1), move->piece);
      turns.resize(turn_number, *move);
      turn_number++;
      updates.push_back(turns.back());
    }
    else
    {
      if(move->square == locations->Undo)
      {
        updates = Undo();
      }
      else
      {
        updates = Redo();
      }      
    }
    return updates;  
  }

  void GameState::Setup_Board(void)
  {
    // By default does nothing
  }

  std::vector<Move> GameState::Undo(void)
  {
    std::vector<Move> update;
    if(Active_AI)
    {
      update.push_back(Move(turns[turn_number].square, pieces->Blank, " "));
      turn_number--;
    }
    update.push_back(Move(turns[turn_number].square, pieces->Blank, " "));
    turn_number--;
    return update;
  }

  std::vector<Move> GameState::Redo(void)
  {
    std::vector<Move> update;
    if(Active_AI)
    {
      update.push_back(turns[turn_number]);
      turn_number++;
    }
    update.push_back(turns[turn_number]);
    turn_number++;
    return update;
  }
/*
  Move AI::Either(Move& a, Move& b)
  {

  }

  Move AI::Open_Space(void)
  {

  }
*/
  PlaySpace::PlaySpace(const Pieces &Pieces, const Locations &Locations, size_t Width, size_t Height)
  {
    pieces = &Pieces;
    locations = &Locations;

    width = Width;
    height = Height;

    undo = "Undo:z";
    redo = "Redo:y";
    removeUndoRedo = "      ";

    Setup_Display();
  }

  void PlaySpace::Setup_Display()
  {
    this->display.resize(height * width); //Sets display size
    this->display.replace(this->display.begin(), this->display.end(), this->display.length(), ' '); //Fills display with whitespace

    this->Write_Header();
    this->Write_Board();
    this->Print_PlaySpace();
  }

  void PlaySpace::Print_PlaySpace()
  {
    for(size_t i = 0; i < this->display.length(); i+= (size_t)this->width)
      {
         std::cout << this->display.substr(i, (size_t)this->width) << std::endl;
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

  Turn_Dialog::Turn_Dialog(Move_Select &move_select)
  {
    select = &move_select;
    move_prompt = "Please make your move: ";
    invalid = "Invalid input, try again: ";
  }
  
  Turn::Turn(Game::AI &AI, Turn_Dialog &Dialog)
  {
    ai = &AI;
    dialog = &Dialog;
  }

  Move Turn::AI(void)
  {
    return ai->Turn();
  }

  Move Turn::Player(void) 
  {
    dialog->Prompt(dialog->move_prompt.length(), dialog->move_prompt);
    return dialog->select->Select();
  }

  Player::Player(std::string Name, bool ai) : Dialog::Option<Player*>(this, Name, " ")
  {
    name = Name;
    CPU = ai;
    score = 0;
  }

  New_Player::New_Player()
  {
    name = "New Player";
    required_input = "0";
    CPU = false;
    score = 0;
    selection = NULL;
  }

  Player_Select::Player_Select(bool ai, std::vector<Player>& ClientList)
  {
    ai_available = ai;
    masterlist = &ClientList;
    currentplayers->clear();
  }

  Player* Player_Select::Add_Player(Player newPlayer)
  {
    masterlist->push_back(newPlayer);
    return &masterlist->back();
  }

  void Player_Select::Generate_List(void)
  {
    Options.push_back(New_Player()); // Sets New Player as an option 

    for(int i = 0; i < masterlist->size(); i++)
    {
      if(!(!ai_available && (*masterlist)[i].CPU)) //skip if user is ai and game does not support
      {
        for(int j = 0; j < currentplayers->size(); j++)
        {
          if((*currentplayers)[j]->name == (*masterlist)[i].name){break;} //if player name is already active
          if(j >= Options.size() - 1) //if end of list is reached
          {
            Options.push_back((*masterlist)[i]);
          }
        }
      }
    }
  }

  BaseDialog::BaseDialog(Player_Select& PlayerSelect)
  {
    playerselect = &PlayerSelect;

    newPlayer_Name = "";
    newPlayer_Ai = "";
    Play_Again = "";
    Round_Winner = "";
    Round_Tie = "";
  }

  void BaseDialog::Select_Players(int num_players)
  {
    while(currentplayers->size() < num_players)
    {
      Player* player = playerselect->Select().On_Select(); 
      if(!player->selection)
      {
        Player_Setup();
      }
      currentplayers->push_back(player);
    }
  }

  Player* BaseDialog::Player_Setup(void)
  {
    std::string PlayerName;
    bool PlayerAI;

    Prompt(this->newPlayer_Name.size(), this->newPlayer_Name);
    std::cin >> PlayerName;

    Prompt(this->newPlayer_Ai.size(), this->newPlayer_Ai);
    PlayerAI = YesNo->Select().On_Select();

    return playerselect->Add_Player(Player(PlayerName, PlayerAI));
  }
}
