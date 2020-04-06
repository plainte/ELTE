//
// Created by molna on 2020. 03. 06..
//

#ifndef SET_TESTING_APP_H
#define SET_TESTING_APP_H

#include "Set.h"
#include <sstream>

namespace mySpace {

  enum class ReturnCode {
    USER_REQUESTED_QUIT,
    ADD_NEW_ELEMENT,
    ERASE_ELEMENT,
    DISPLAY_MAX,
    CHECK_STATUS,
    DISPLAY_SET,
    CLR_AND_REFRESH,
    INVALID
  };

  class App
  {
  public:
    App() : sPtr(new Set({})) {}
    void Run();
  private:
    SetPtr sPtr;

    void AddElement();
    void EraseElement();
    void CheckIfSetEmpty();
    void DisplayMaxElement();
    void DisplaySet();
    int Menu();
    void DisplayMenuOptions();
    void ClearSurface();
    void GoodBye();
    std::istringstream GetInput();
    int HandleInput();
    int HandleElement();
    ReturnCode ProcessInput(int action);

  };

}


#endif //SET_TESTING_APP_H
