#include "GameComponents.hpp"

namespace Game
{
  Move::Move(Location Square, Piece Piece, std::string Required_Input) : Dialog::Option<Move*>(selection, name, Required_Input)
  {
    name = " ";
    required_input = Required_Input;
    selection = this;
    piece = Piece;
    square = Square;
  }
  
  Move_Select::Move_Select(int Input_Length) : Dialog::Option_Select<Game::Move>(Input_Length)
  {
    user_input = "";
    if(!input_length) {input_length = Input_Length;}
  }

  void Move_Select::Print_List(void)
  {
    //Do nothing
  }

  GameState::GameState(Pieces &Pieces, Locations &Locations, size_t BoardSize, bool Active_AI)
  {
    active_ai = Active_AI;
    if(!pieces) {pieces = &Pieces;}
    if(!locations) {locations = &Locations;}
    turns.clear();
    board.resize(BoardSize, pieces->Blank);
    turn_number = 0;

    Setup_Board();
  }

  std::vector<Move> GameState::Update(Move& move)
  {
    std::vector<Move> updates;

    if(move.piece)
    {
      board.erase(board.begin() + (move.square - 1));
      board.insert(board.begin() + (move.square - 1), move.piece);
      turns.resize(turn_number, move);
      turn_number++;
      updates.push_back(turns.back());
    }
    else
    {
      if(move.square == locations->Undo)
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
    if(active_ai)
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
    if(active_ai)
    {
      update.push_back(turns[turn_number]);
      turn_number++;
    }
    update.push_back(turns[turn_number]);
    turn_number++;
    return update;
  }

  AI::AI(GameState& Gamestate)
  {
    gamestate = &Gamestate;
  }
/*
  Move AI::Either(Move& a, Move& b)
  {

  }

  Move AI::Open_Space(void)
  {

  }
*/
  PlaySpace::PlaySpace(Pieces &Pieces, Locations &Locations, int Display_Width, int Display_Height)
  {
    if(!pieces) {pieces = &Pieces;} // will all these need this->????
    if(!locations) {locations = &Locations;}

    if(!width) {width = Display_Width;}
    if(!height) {height = Display_Height;}

    if(undo.empty()) {undo = "Undo:z";}
    if(redo.empty()) {redo = "Redo:y";}
    if(removeUndoRedo.empty()) {removeUndoRedo = "      ";}

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

  Turn_Dialog::Turn_Dialog()
  {
    if(!select) {std::cout << "ERROR: NO MOVE SELECT IMPLEMENTED"; abort();}
    if(move_prompt.empty()) {move_prompt = "Please make your move: ";}
    if(invalid.empty()) {invalid = "Invalid input, try again: ";}
  }
  
  Turn::Turn(std::vector<Game::Player>& Client_List)
  {
    bool ai_implemented = true;
    if(!ai) {ai = NULL, ai_implemented = false;}
    if(!dialog) {dialog = new Turn_Dialog();}

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

  Player_Select::Player_Select(bool AI_Available, std::vector<Player>& ClientList) : Dialog::Option_Select<Game::PLayer>(input_length)
  {
    input_length = 1;
    ai_available = AI_Available;
    if(!client_list) {client_list = &ClientList;}
    current_players->clear(); // this might also need to be inline, not sure
  }

  Player* Player_Select::Add_Player(Player newPlayer)
  {
    client_list->push_back(newPlayer);
    return &client_list->back();
  }

  void Player_Select::Generate_List(void)
  {
    Options.push_back(New_Player()); // Sets New Player as an option 

    for(int i = 0; i < client_list->size(); i++)
    {
      if(!(!ai_available && (*client_list)[i].CPU)) //skip if user is ai and game does not support
      {
        for(int j = 0; j < current_players->size(); j++)
        {
          if((*current_players)[j]->name == (*client_list)[i].name){break;} //if player name is already active
          if(j >= Options.size() - 1) //if end of list is reached
          {
            Options.push_back((*client_list)[i]);
          }
        }
      }
    }
  }

  BaseDialog::BaseDialog(bool AI_Available , std::vector<Player>& Client_List)
  {
    if(!player_select) {player_select = new Player_Select(AI_Available, Client_List);}

    newPlayer_Name = "";
    newPlayer_Ai = "";
    Play_Again = "";
    Round_Winner = "";
    Round_Tie = "";

    YesNo = Dialog::YesNo_Select::Get_Instance();
  }

  void BaseDialog::Select_Players(int num_players)
  {
    while(current_players->size() < num_players)
    {
      Player* player = player_select->Select().On_Select(); 
      if(!player->selection)
      {
        Player_Setup();
      }
      current_players->push_back(player);
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

    return player_select->Add_Player(Player(PlayerName, PlayerAI));
  }
}
