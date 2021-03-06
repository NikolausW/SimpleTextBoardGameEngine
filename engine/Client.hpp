///////////////////////////////////////////////
#ifndef CLIENT_HPP
#define CLIENT_HPP
///////////////////////////////////////////////
#include "Dialog.hpp"
#include "GameCore.hpp"
#include "GameComponents.hpp"
#include "GameList.hpp"
#include <iostream>

namespace Client
{
  class Game_Select : public Dialog::Option_Select<Game::Option>
  {
    public:
      static Game_Select* Get_Instance(std::vector<Game::Player>& Client_List); // Singleton call method
      // void Select(Game::Option);
    protected:
      // int Input_Length;
      // std::string User_Input(void);    
      // std::vector<Game::Option> Options;
      std::vector<Game::Player>* client_list = NULL;

      // void Print_List(void);
      // std::string Generate_Option_String(Game::Option* option);
      // std::string Take_Input(void);
      // bool Validate_Input(std::string input);
      // Game::Option* Process_Input(void);
      void Generate_List(void);
    private:
      static Game_Select* Instance; // Pointer to itself
      Game_Select(std::vector<Game::Player>& Client_List); // private constructor 
  };

  class Client_Dialog : public Dialog::Base
  {
    //Need to include strings for Welcome, Play_Again, and Thank you 
    public:
      Client_Dialog(std::vector<Game::Player>& Client_List);
      Game_Select* gameselect;
      std::string welcome,
                  thankYou;
      // void Prompt(size_t width, std::string str);
      // YesNo_Select* YesNo;
      // void Clear_Screen(void);
  };

  class Instance
  {
    public:
      Instance();
      void Instance_Loop(void);
      std::vector<Game::Player> playerlist;
    private:
      Game::Base* currentgame = NULL;
      Client_Dialog* dialog;

      void Different_Game(void);
      void Exit(void);
  };
}
#endif
