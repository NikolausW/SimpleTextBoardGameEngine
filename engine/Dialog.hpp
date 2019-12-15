///////////////////////////////////////////////
#ifndef DIALOG_HPP
#define DIALOG_HPP
///////////////////////////////////////////////
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace Dialog
{
  class Option
  {
    public:
      std::string Name,
                  Required_Input;
      virtual bool Conditional(void); 
      //probably needs On_Select() method template
  };

  class Option_Select
  {
    public:
      virtual Option* Select(void); //Kicks off below methods and returns user selected option
    protected:
      int Input_Length;
      std::vector<Option> Options; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(Option* option); //Constructs the strings that print list will print 
      virtual std::string Take_Input(void); //Simply takes the input from user
      virtual bool Validate_Input(std::string input); //Validates received input
      virtual void Generate_List(void) = 0;
  };

  class YesNo_Option : public Option
  {
    public:
      YesNo_Option(bool YN);
      bool On_Select(); //yesno
      bool selection;
  };

  class YesNo_Select : public Option_Select
  {
    public:
      static YesNo_Select* option_select();
    protected:
      void Print_List(void);
      std::string Generate_Option_String(Option* option); 
      void Generate_List(void);
    private:
      YesNo_Select();
      static YesNo_Select* Instance;
  };

  class Base
  {
    public:
      Base();
      virtual void Prompt(size_t width, std::string str);
      YesNo_Select* YesNo;
      virtual void Clear_Screen(void);  
  };
}
#endif
