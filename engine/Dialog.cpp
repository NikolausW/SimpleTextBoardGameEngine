#include "Dialog.hpp"

namespace Dialog
{
  void Dialog::Prompt(size_t width, std::string str)
  {
    for(size_t i = 0; i < str.length(); i += width)
    {
      std::cout << str.substr(i, width) << std::endl;
    }
  }

  std::string Dialog::Receive_Input(size_t length)
  {
    std::string input;
    getline(std::cin, input);
    input.resize(length);
    return input;
  }

  bool Dialog::YesNo(void)
  {
    std::string input = Receive_Input(1);
    switch(input)
    {
      case "y": return true;
      case "n": return false;
      default: return YesNo();
    }  
  }

  GamePlay::Game* Instance::Game_Select(void)
  {

  }

  void Game::Player_Select(int numPlayers)
  {

  }

  void Game::Player_Setup(GamePlay::Player* newPlayer)
  {

  }


}
