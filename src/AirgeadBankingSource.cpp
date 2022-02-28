//=============================================
// Name of App : CS_210_AirgeadBanking
// Date        : Feb 2nd, 2022
// Class       : CS-210
// Author      : Jose Martinez
//=============================================
#include <iostream>
#include <string>
#include "../src/modules/displayInterface/DisplayInterface.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
int main() {

    // Injecting the DisplayInterface
    DisplayInterface displayInterface;

    // Running the main menu to start our application
    displayInterface.mainMenu();

    return 0;
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
