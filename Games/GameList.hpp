///////////////////////////////////////////////
#ifndef GAMELIST_HPP
#define GAMELIST_HPP
///////////////////////////////////////////////
#include "GameCore.hpp"
#include "Dialog.hpp"
#include <vector>

namespace Game
{
  class Option : public Dialog::Option
  {
    public:
      Option(std::string gameName, Base* game);
      Base* On_Select(void); 
    private:
      Base* selection;
  };
  
  std::vector<Option> GameList;
  std::vector<Option> PopulateGameList(void);

  //If you want to add a new game type add line to populte game options method

}

#endif
