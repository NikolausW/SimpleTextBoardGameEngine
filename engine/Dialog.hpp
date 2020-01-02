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
      virtual T On_Select(void); // can maybe get rid of this method? If all it does is return selection
      T selection; // What the option returns
  };

  template <class T> // By default returns the object itself 
  class Option_Select
  {
    public:
      // Option_Select(); // Should this be private?
      // Constructor for passing in list of options?
      virtual T* Select(void); //Kicks off below methods and returns a pointer to the user selected option
      virtual void Select(T& option); // THIS MIGHT NOT BE NEEDED? Probably not needed
    protected:
      int Input_Length; // expected input length
      // std::string User_Input; // Likely delete this
      std::vector<T> Options; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(T* option); //Constructs the strings that print list will print 
      std::string Take_Input(void); //Simply takes the input from user
      bool Validate_Input(std::string input); //Validates received input
      T* Process_Input(void); // Translates validated input to an Option
      virtual void Generate_List(void) = 0; // This should generate Required_Input if it creates the options itself
  };

  class YesNo_Option : public Option<bool>
  {
    public:
      YesNo_Option(bool YN); // Constructor
      //std::string Name,
      //            Required_Input;
      // bool Conditional(void);
      // bool On_Select();
      // bool selection;
  };

  class YesNo_Select : public Option_Select<YesNo_Option>
  {
    public:
      static YesNo_Select* Get_Instance();
      // YesNo_Option* Select(void);
    protected:
      // int Input_Length;
      // std::string User_Input(void);
      // std::vector<YesNo_Option> Options;

      virtual void Print_List(void);
      virtual std::string Generate_Option_String(YesNo_Option* option);
      // std::string Take_Input(void);
      // bool Validate_Input(std::string input);
      // YesNo_Option* Process_Input(void);
      virtual void Generate_List(void);
    private:
      YesNo_Select();
      static YesNo_Select* Instance;
  };

  class Base
  {
    public:
      Base();
      void Prompt(size_t width, std::string str);
      YesNo_Select* YesNo;
      void Clear_Screen(void);  
  };
}
#endif