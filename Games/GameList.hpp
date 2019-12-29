///////////////////////////////////////////////
#ifndef GAMELIST_HPP
#define GAMELIST_HPP
///////////////////////////////////////////////
#include "GameCore.hpp"
#include "Dialog.hpp"
#include <vector>
#include <string>
//Include Your Game Header Here
#include "TicTacToe/TicTacToe.hpp"


namespace Game
{
  class Option : public Dialog::Option<Base*>
  {
    public:
      Option(std::string gameName, Base* game);
      // std::string Name,
      //             Required_Input;
      // bool Conditional(void);
      // Base* On_Select(void); 
      // Base* selection;
  };
  
  std::vector<Game::Option> GameList; // Simply the list of available game, keeps generated games in scope by storing it here
  std::vector<Dialog::Option<Game::Base*>> PopulateGameList(void);

  //If you want to add a new game type add line to populate game options function in GamesList.cpp
}

#endif
