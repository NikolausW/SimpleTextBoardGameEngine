///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
//#include "Player.hpp"
#include "GamePlay.hpp"
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

  class Option_Select
  {
    public:    
      virtual Option* Select(void); //Kicks off below methods and returns user selected option
    protected:
      int Input_Length;
      std::vector<Option> List; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(Option* option); //Constructs the strings that print list will print 
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
      std::string Generate_Option_String(Option* option);
      void Generate_List(void);
    private:
      Yes_No();
      static Yes_No* Instance;
  };

  class Option
  {
    public:
      std::string Name,
                  Required_Input;
      virtual bool Conditional(void);      
  };

  class YN_Option : public Option
  {
    public:
      YN_Option(bool YN);
      bool On_Select(); //yesno
      bool selection;
  };
}

#endif
