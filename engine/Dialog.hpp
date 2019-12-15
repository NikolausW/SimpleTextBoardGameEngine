///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
#include "Option.hpp"
#include "OptionSelect.hpp"
#include <string>
#include <iostream>
#include <vector>


namespace Dialog
{
  class Dialog
  {
    public:
      virtual void Prompt(size_t width, std::string str);
      Yes_No* YesNo;
      virtual void Clear_Screen(void);
    private:    
  };

  class Instance : public Dialog
  {
    //Need to include strings for Welcome, Play_Again, and Thank you 
    public:
      Instance();
      Game_Select gameSelect;
      std::string welcome,
                  thankYou;
  };

  class Game : public Dialog
  {
    //Need to include strings for Turn and Again Prompt, Round Winner, and Round Tie
    public:  
      Player_Select PlayerSelect; 
      //virtual void Player_Setup(void); //calls the player constructor returnin a new player object
  };

  //TURN DIALOG GOES HERE
}

#endif
