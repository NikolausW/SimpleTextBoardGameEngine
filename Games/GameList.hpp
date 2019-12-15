///////////////////////////////////////////////
#ifndef GAMELIST_HPP
#define GAMELIST_HPP
///////////////////////////////////////////////
#include "GameCore.hpp"
#include "Dialog.hpp"

namespace Game
{
//vector of Game Options
class Option : public Dialog::Option
{
  public:
    Option(int number, Base* game);
    Base* On_Select(void); //Game_Select
  private:
    Base* selection;
};
//method for populating Game Options vector

//If you want to add a new game type add line to populte game options method

}

#endif
