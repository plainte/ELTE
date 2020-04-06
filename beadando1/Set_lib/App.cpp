//
// Created by molna on 2020. 03. 06..
//

#define WINDOWS

#include "App.h"

namespace mySpace {

  void App::DisplayMaxElement()
  {
    if (sPtr->maxElement().has_value()) {
      std::cout << "The highest value in the set is: " << sPtr->maxElement().value() << "\n";
    } else {
      std::cout << "The set is empty\n";
    }
  }

  void App::Run()
  {
    auto running = true;
    while(running) {
      switch (ProcessInput(Menu())) {
        case ReturnCode::USER_REQUESTED_QUIT:
          running=false;
          GoodBye();
          break;
        case ReturnCode::ADD_NEW_ELEMENT:
          AddElement();
          break;
        case ReturnCode::ERASE_ELEMENT:
          EraseElement();
          break;
        case ReturnCode::DISPLAY_MAX:;
          DisplayMaxElement();
          break;
        case ReturnCode::CHECK_STATUS:;
          CheckIfSetEmpty();
          break;
        case ReturnCode::DISPLAY_SET:;
          DisplaySet();
          break;
        case ReturnCode::CLR_AND_REFRESH:
          ClearSurface();
          break;
        default:
          ClearSurface();
          break;
      }
    }
  }

  void App::AddElement()
  {
    std::cout << "Please enter the element: ";
    auto e = HandleElement();
    if (sPtr->pushBack(e)) {
      std::cout << "Successfully inserted: " << e << "\n\n";
    } else {
      std::cout << "The value: " << e << " is already in the set\n\n";
    }
  }

  void App::EraseElement()
  {
    std::cout << "Please enter the element: ";
    auto e = HandleElement();
    if (sPtr->erase(e)) {
      std::cout << "Successfully erased: " << e << "\n\n";
    } else {
      std::cout << "The value: " << e << " is not in the set\n\n";
    }
  }

  void App::CheckIfSetEmpty()
  {
    if (sPtr->isEmpty()) {
      std::cout << "The set is empty\n\n";
    } else {
      std::cout << "The set isn't empty - to display the set press 6!\n\n";
    }
  }

  std::istringstream App::GetInput()
  {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    return iss;
  }

  int App::HandleInput()
  {
    std::cout << "Please enter your selection: ";
    auto ac = -1;
    do {
      GetInput() >> ac;
    } while (ac == -1);
    return ac;
  }

  int App::Menu()
  {
    DisplayMenuOptions();
    return HandleInput();
  }

  void App::DisplayMenuOptions()
  {
    std::cout << "----------------------------------\n";
    std::cout << "Please select from the following options\n";
    std::cout << " 0. - Quit\n";
    std::cout << " 1. - Add new element to set\n";
    std::cout << " 2. - Erase element from set\n";
    std::cout << " 3. - Display highest element\n";
    std::cout << " 4. - Check set empty status\n";
    std::cout << " 5. - Display the set\n";
    std::cout << " 6. - Clear the surface and refresh menu\n";
    std::cout << "----------------------------------\n\n";
  }
#ifdef WINDOWS
  void App::ClearSurface()
  {
    system("clr");
  }
#endif

  ReturnCode App::ProcessInput(int action)
  {
    auto returnCode = ReturnCode::INVALID;
    switch (action) {
      case 0: returnCode = ReturnCode::USER_REQUESTED_QUIT; break;
      case 1: returnCode = ReturnCode::ADD_NEW_ELEMENT;     break;
      case 2: returnCode = ReturnCode::ERASE_ELEMENT;       break;
      case 3: returnCode = ReturnCode::DISPLAY_MAX;         break;
      case 4: returnCode = ReturnCode::CHECK_STATUS;        break;
      case 5: returnCode = ReturnCode::DISPLAY_SET;         break;
      case 6: returnCode = ReturnCode::CLR_AND_REFRESH;     break;
    }
    return returnCode;
  }

  void App::GoodBye()
  {
    std::cout << "Hope to see you next time!\n";
    std::cout << "Press any key to close the window!\n";
    std::getchar();
  }

  int App::HandleElement()
  {
    auto e = -555;
    auto counter = 3;
    do {
      GetInput() >> e;
      if (e == -555) {
        std::cout << "If you're trying to enter '-555' please enter it twice!\n";
      }
    } while (e == -555 && counter-- > 0);
    return e;
  }

  void App::DisplaySet()
  {
     std::cout << *sPtr;
  }


}