///////////////////////////////////////////////
#ifndef GAMELIST_HPP
#define GAMELIST_HPP
///////////////////////////////////////////////
#include "../engine/GameComponents.hpp"
#include "../engine/Dialog.hpp"
#include <vector>
#include <string>
//Include Your Game Header Here
#include "TicTacToe/TicTacToe.hpp"


namespace Game
{
  enum Games
  {
    TicTacToe
  };

  struct GameData
  {
    GameData();
    int PlayerCount = 0;
    size_t Board_Width = 0, 
           Board_Height = 0,
           Display_Width = 0,
           Display_Height = 0;
    Locations* locations = NULL;
    Pieces* pieces = NULL;
    BaseDialog* GameDialog = NULL;
    GameState* Gamestate = NULL;
    PlaySpace* PlaySpace = NULL;
    AI* ai = NULL;
    Turn* Turn = NULL;
    Turn_Dialog* Turn_Dialog = NULL;
    Player_Select* PlayerSelect = NULL;
  };
  
  class Option : public Dialog::Option<GameData>
  {
    public:
      Option(std::string GameName, Games GameType);
      // std::string Name,
      //             Required_Input;
      Games game;
      // bool Conditional(void);
      void On_Select(GameData& option); 
      // GameData selection; // by default will be empty
    private:
      Option();
  };
  
  std::vector<Game::Option> GameList; // Simply the list of available game, keeps generated games in scope by storing it here
  void PopulateGameList(std::vector<Game::Option>& gamelist);

  //If you want to add a new game type add line to populate game options function in GamesList.cpp

  
}

#endif
