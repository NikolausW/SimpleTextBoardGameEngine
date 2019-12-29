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
  template <class T>
  class Option
  {
    public:
      std::string Name,
                  Required_Input;  
      virtual bool Conditional(void); // by default the option is always allowed
      virtual T On_Select(); // can maybe get rid of this method? If all it does is return selection
      T selection; // What the option returns
  };

  template <class T> // By default returns the object itself 
  class Option_Select
  {
    public:
      Option_Select();
      virtual Option<T>* Select(void); //Kicks off below methods and returns a pointer to the user selected option
    protected:
      int Input_Length;
      std::string User_Input;
      std::vector<Option<T>> Options; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(Option<T>* option); //Constructs the strings that print list will print 
      virtual std::string Take_Input(void); //Simply takes the input from user
      virtual bool Validate_Input(std::string input); //Validates received input
      virtual Option<T>* Process_Input(void); // Translates validated input to an Option
      virtual void Generate_List(void) = 0;
  };

  class YesNo_Option : public Option<bool>
  {
    public:
      YesNo_Option(bool YN); // Constructor
      //std::string Name,
      //            Required_Input;
      // bool Conditional(void);
      // bool On_Select(); //yesno
      // bool selection;
  };

  class YesNo_Select : public Option_Select<bool>
  {
    public:
      static YesNo_Select* Get_Instance();
      // YesNo_Option* Select(void);
    protected:
      // int Input_Length;
      // std::string User_Input(void);
      // std::vector<YesNo_Option> Options;

      void Print_List(void);
      std::string Generate_Option_String(Option<bool>* option); 
      // std::string Take_Input(void);
      // bool Validate_Input(std::string input);
      // YesNo_Option* Process_Input(void);
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