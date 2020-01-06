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
      std::string name = "",
                  required_input = "";  
      virtual bool Conditional(void); // by default the option is always allowed
      virtual T On_Select(void); 
      T selection; // What the option returns
  };

  template <class T> // By default returns the object itself 
  class Option_Select
  {
    public:
      explicit Option_Select(int Input_Length);
      virtual T Select(void); //Kicks off below methods and returns a pointer to the user selected option
    protected:
      int input_length = 0; // expected input length
      std::string user_input = "";
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
      // Option<bool>* Select(void);
    protected:
      // int input_length;
      // std::string User_Input;
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