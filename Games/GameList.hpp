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
  
  class Option : public Dialog::Option<Base*>
  {
    public:
      Option(std::string Game_Name, Games Game_Type, std::vector<Game::Player>& Client_List);
      // std::string name,
      //             required_input;
      Games game; //enumeration, I think this could be replaced with Name, enumeration forces uniqueness though
      std::vector<Player>* client_list; 
      // bool Conditional(void);
      Base* On_Select(void); 
      // Base* selection; // by default will be empty
    private:
      Option();
  };
  
  void PopulateGameList(std::vector<Game::Option>& Game_List, std::vector<Player>& Client_List);

  //If you want to add a new game type add line to populate game options function in GamesList.cpp

  
}

#endif
