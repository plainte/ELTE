#include "App.h"
#include <iostream>

#define WINDOWS

#ifdef WINDOWS
int main() {
    App::Run();
    std::cout << "Please enter a key to quit..." << std::endl;
    std::getchar();
    return 0;
}
#else
int main() {
    return App::Run();
}
#endif
