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
      explicit Option(T Selection, std::string Name, std::string Required_Input);
      std::string name,
                  required_input;  
      virtual bool Conditional(void); // by default the option is always allowed
      virtual T On_Select(void); // can maybe get rid of this method? If all it does is return selection
      T selection; // What the option returns
  };

  template <class T> // By default returns the object itself 
  class Option_Select
  {
    public:
      // Option_Select(); // Should this be private?
      virtual T Select(void); //Kicks off below methods and returns a pointer to the user selected option
      // virtual void Select(T& option); // THIS MIGHT NOT BE NEEDED? Probably not needed
    protected:
      int input_length; // expected input length
      std::string user_input;
      std::vector<T> Options; //List of Options to be selected from

      virtual void Print_List(void); //Prints Options
      virtual std::string Generate_Option_String(T* option); //Constructs the strings that print list will print 
      std::string Take_Input(void); //Simply takes the input from user
      bool Validate_Input(std::string& input); //Validates received input
      T* Process_Input(void); // Translates validated input to an Option
      virtual void Generate_List(void) = 0; // This should generate Required_Input if it creates the options itself
  };

  class YesNo_Select : public Option_Select<Option<bool> >
  {
    public:
      static YesNo_Select* Get_Instance();
      // YesNo_Option* Select(void);
    protected:
      // int input_length;
      // std::string User_Input(void);
      // std::vector<Option<bool>> Options;

      virtual void Print_List(void);
      virtual std::string Generate_Option_String(Option<bool>* option);
      // std::string Take_Input(void);
      // bool Validate_Input(std::string input);
      // Option<bool>* Process_Input(void);
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