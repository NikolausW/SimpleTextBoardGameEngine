///////////////////////////////////////////////
#ifndef OPTIONSELECT_HPP
#define OPTIONSELECT_HPP
///////////////////////////////////////////////
#include "Option.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace OptionSelect
{
  class Option_Select
  {
    public:    
      virtual Option::Option* Select(void); //Kicks off below methods and returns user selected option
    protected:
      int Input_Length;
      std::vector<Option::Option> List; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(Option::Option* option); //Constructs the strings that print list will print 
      virtual std::string Take_Input(void); //Simply takes the input from user
      virtual bool Validate_Input(std::string input); //Validates received input
      virtual void Generate_List(void) = 0;
  };

  class Yes_No : public Option_Select
  {
    public:
      static Yes_No* option_select();
    protected:
      void Print_List(void);
      std::string Generate_Option_String(Option::Option* option);
      void Generate_List(void);
    private:
      Yes_No();
      static Yes_No* Instance;
  };

  class Player : Option_Select
  {
    public:
      Player(int numPlayers); //will call option select numPlayers number of times
    protected:
      void Generate_List(void);
    private:
      int Num_Players;
  };

  class Move_Select : public Option_Select
  {
    //need to override either Select or PrintList to remove/replace output
  };

  class Game : public Option_Select //why did I make this a singleton?
  {
    public:
      static Game* option_select();
    protected:
      void Generate_List(void);
    private:
      Game();
      static Game* Instance;
  };  
}
#endif
