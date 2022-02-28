//=============================================
// Name of App : CS_210_AirgeadBanking
// Date        : Feb 2nd, 2022
// Class       : CS-210
// Author      : Jose Martinez
//=============================================
#ifndef AIRGEADBANKING_DISPLAYINTERFACE_H
#define AIRGEADBANKING_DISPLAYINTERFACE_H

#include <iostream>
#include<iomanip>
// Path to bank header file on my mac 
#include "../../modules/bank/Bank.h"

using namespace std;
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
// This interface is going to not only deal with displaying the
// program as the user inputs data but the methods in this class
// will also deal with most of the application's logic. As it
// extends the Bank object to complete that task
class DisplayInterface: public Bank {
private:
    int i;
    int choice = 3;
    float openAmount;
    float opening;
    float deposit;
    float interest;
    float rate;
    float balance;
    int years;
    bool loop = true;
public:
    void mainMenu();
    void depositMenu();
    void withoutDepositsMenu();
    void openingMenuVerification();
    void DisplayUIHelper(string displayHeader) const;
};
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
#endif //AIRGEADBANKING_DISPLAYINTERFACE_H
