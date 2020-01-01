#include "GameComponents.hpp"

namespace Game
{  
  PlaySpace::PlaySpace(const Pieces &Pieces, const Locations &Locations, size_t Width, size_t Height)
  {
    pieces = &Pieces;
    locations = &Locations;

    width = Width;
    height = Height;

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

  GameState::GameState(const Pieces &Pieces, const Locations &Locations, size_t BoardSize)
  {
    pieces = &Pieces;
    locations = &Locations;
    board.resize(BoardSize, pieces->Blank);
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
      update.push_back(Move(turns[turn_number].square, pieces->Blank));
      turn_number--;
    }
    update.push_back(Move(turns[turn_number].square, pieces->Blank));
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

  Move::Move(Location Square, Piece Piece)
  {
    selection = this;
    piece = Piece;
    square = Square;
  }

  void Move_Select::Print_List(void)
  {
    //Do nothing
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

  Move* Turn::AI(void)
  {
    return ai->Turn();
  }

  Move* Turn::Player(void) 
  {
    dialog->Prompt(dialog->move_prompt.length(), dialog->move_prompt);
    return dialog->select->Select();
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

  Player_Select::Player_Select(bool ai, std::vector<Player>& ClientList)
  {
    ai_available = ai;
    masterlist = &ClientList;
  }

  Player* Player_Select::Add_Player(Player newPlayer)
  {
    masterlist->push_back(newPlayer);
    return &masterlist->back();
  }

  void Player_Select::Generate_List(void)
  {
    Options.push_back(newPlayer()); // Sets New Player as an option 

    for(int i = 0; i < masterlist->size(); i++)
    {
      if(!(!ai_available && (*masterlist)[i].CPU)) //skip if user is ai and game does not support
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

  BaseDialog::BaseDialog(Player_Select& PlayerSelect)
  {
    playerselect = &PlayerSelect;

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
      Player* player = playerselect->Select(); 
      if(!player)
      {
        Player_Setup();
      }
      Current_Players.push_back(player);
    }
    return Current_Players;
  }

  void BaseDialog::Player_Setup(void)
  {
    std::string PlayerName;
    bool PlayerAI;

    Prompt(newPlayer_Name.size(), newPlayer_Name);
    std::cin >> PlayerName;

    Prompt(newPlayer_Ai.size(), newPlayer_Ai);
    PlayerAI = YesNo->Select()->On_Select();

    playerselect->Add_Player(Player(PlayerName, PlayerAI));
  }
}
