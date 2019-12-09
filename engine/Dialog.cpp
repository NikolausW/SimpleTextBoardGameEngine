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

  void Dialog::Clear_Screen()
  {
    for(int i = 50; i > 0; i--)
    {
      std::cout << "\n";
    }
  }

  Instance::Instance()
  {
    welcome = "Welcome";
    thankYou = "Thank you for playing!";
  };

  //GAME DIALOG GOES HERE

  //TURN DIALOG GOES HERE
}
