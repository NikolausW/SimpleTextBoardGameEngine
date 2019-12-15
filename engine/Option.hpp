///////////////////////////////////////////////
#ifndef OPTION_HPP
#define OPTION_HPP
///////////////////////////////////////////////
#include "GameCore.hpp"
#include <string>

namespace Option
{
  class Option
  {
    public:
      std::string Name,
                  Required_Input;
      virtual bool Conditional(void); 
      //probably needs On_Select() method     
  };

  class YesNo : public Option
  {
    public:
      YesNo(bool YN);
      bool On_Select(); //yesno
      bool selection;
  };

  class Player : public Option //What the actually fuck is wrong with this implementation?
  {
    public:
      void On_Select(std::vector<Player*>* players); //Player Select, this should return a list of players, not take one
      std::string Name; //Already part of the base Option class
      int score;
      bool CPU;
  };

  class Move : public Option
  {
    Move* On_Select(int square); //Turn_Select
    int square;  
  };

  class Game : public Option
  {
    public:
      Game(int number, GameCore::Game* game);
      GameCore::Game* On_Select(void); //Game_Select
    private:
      GameCore::Game* selection;
  };
}
#endif
