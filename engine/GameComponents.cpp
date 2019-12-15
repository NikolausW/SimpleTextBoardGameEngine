#include "GameComponents.hpp"

namespace Game
{
  Move Turn::AI(void)
  {
    return ai->Turn();
  }

  PlaySpace::PlaySpace()
  {
    undo = "Undo:z";
    redo = "Redo:y";
  }

  void PlaySpace::Write_PlaySpace()
  {
    Write_Header();
    Write_Board();
    Write_PlaySpace();
  }

  void PlaySpace::Print_PlaySpace()
  {
    for(size_t i = 0; i < display.length(); i+= (size_t)width)
      {
         std::cout << display.substr(i, (size_t)width) << std::endl;
      }
  }

  void PlaySpace::Write_UndoRedo(bool un, bool re)
  {
    if(un){display.replace(Get_Coordinate(Locations{Redo}), redo.length(), redo);}
    else{display.replace(Get_Coordinate(Locations{Undo}), removeUndoRedo.length(), removeUndoRedo);} 
  }

  Move Turn::Player(void)
  {
    //return dialog->Receive_Input()
  }

  //TURN DIALOG GOES HERE

  //Move_Select Goes Here

  //Move Option Goes here

  //Player Option Implementation Goes Here

 Player_Select::Player_Select(int numPlayers)
  {
    for(int i = numPlayers; i > 0; i--)
    {
      
    }
  }

  //Player Generate_List Goes here
}
