//=============================================
// Name of App : CS_210_AirgeadBanking
// Date        : Feb 2nd, 2022
// Class       : CS-210
// Author      : Jose Martinez
//=============================================
#include "DisplayInterface.h"

// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰

// The main menu method deals with the initial start of the program & the
// data needed from the user to implement the rest of the application
void DisplayInterface::mainMenu() {

    cout << "\n";
    cout << "===============Data Input==============\n";
    cout << "Enter Initial Investment Amount: \n";

    cin >> opening;
    openAmount = opening;

    // Makes sure the user inputs a valid value, if they don't they will be prompted to do so
    if (opening < 0) {
        cout << "Invalid Entry: Try Again." << endl;
        mainMenu();
    }

    Bank::SetInitialBalanceAmount(opening);
    cout << "Enter Monthly Deposit: \n";
    cin >> deposit;

    if (deposit < 0) {
        cout << "Invalid Entry: Try Again." << endl;
        mainMenu();
    }
    Bank::SetMonthlyDeposit(deposit);
    cout << "Enter Annual Interest: \n";
    cin >> interest;

    if (interest < 0) {
        cout << "Invalid Entry: Try Again." << endl;
        mainMenu();
    }

    Bank::SetAnnualInterest(interest);
    cout << "Enter Number of Years: \n";
    cin >> years;
    cout << endl;

    if (years < 0) {
        cout << "Invalid Entry: Try Again." << endl;
        mainMenu();
    }

    Bank::SetNumYears(years);
    openingMenuVerification();
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰

// This method is used to capture the data inputted by the user in the
// mainMenu method & run some calculations to then display the results
// in a table format, in the console.The data would be displayed with a monthly
// deposit every month, set by the user input in the main menu method
void DisplayInterface::depositMenu() {

    DisplayUIHelper("Balance and Interest With Additional Monthly Deposits");

    SetInitialBalanceAmount(openAmount);

    // For loop to output all the years into months the user inputted
    for (i = 0; i < Bank::yearsToMonths(); ++i) {
        opening = GetInitialBalanceAmount();
        rate = ((opening + deposit) * (GetAnnualInterestRate() / 100.00) / 12.00);
        balance = opening + deposit + rate;

        cout << setprecision(2) << fixed << "|    " << setfill(' ') << setw(2) << (i + 1) << "       ||" << setfill(' ')
             << setw(12) << opening << "           |";
        cout << "| " << setfill(' ') << setw(10) << deposit << "          || " << setfill(' ') << setw(8)
             << (opening + deposit) << "   |";
        cout << "| " << setfill(' ') << setw(10) << rate << "           ||" << setfill(' ') << setw(10) << balance
             << "       |" << endl;
        SetInitialBalanceAmount(balance);
    }
    cout << setfill(' ') << setw(25)
         << " =====================================================================================================================\n";
    cout << setfill(' ') << setw(25)
         << " =====================================================================================================================\n";
    cout << "" << endl;

    cout << "Press 1 to change Initial Data or Press 2 to exit:\n";
    //This is a while loop that ask the user if they would like to change the initial data or quit the programO
    while (loop) {
        cin >> choice;

        switch (choice) {
            case 1:
                mainMenu();
                loop = false;
                break;
            case 2:
                exit(1);
            default:
                cout << "Press 1 to change Initial Data or Press 2 to exit:\n";
                loop = true;
        }
    }
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰

// Similar to the depositMenu method, this method is used to capture
// the data but the caveat is that there is no monthly deposit
void DisplayInterface::withoutDepositsMenu() {

    DisplayUIHelper("Balance and Interest Without Additional Monthly Deposits");

    // For loop to output all the years into months the user inputted
    for (i = 0; i < Bank::yearsToMonths(); ++i) {
        opening = GetInitialBalanceAmount();
        rate = (opening + 0) * (GetAnnualInterestRate() / 100.00) / 12.00;
        balance = opening + rate;

        cout << setprecision(2) << fixed << "|    " << setfill(' ') << setw(2) << (i + 1) << "       ||" << setfill(' ')
             << setw(12) << opening << "         |";

        cout << "| " << setfill(' ') << setw(10) << 0 << "          || " << setfill(' ') << setw(8) << (opening + 0)
             << "   |";

        cout << "| " << setfill(' ') << setw(10) << rate << "           ||" << setfill(' ') << setw(10) << balance
             << "        |" << endl;

        SetInitialBalanceAmount(balance);
    }

    cout << setfill(' ') << setw(25)
         << " =================================================================================================================\n";
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰

// This is a helper function to cut down on the amount of boilerplate code
void DisplayInterface::DisplayUIHelper(string displayHeader) const {

    cout << "\n" << setfill(' ') << setw(90) << displayHeader << "         \n";

    cout << setfill(' ') << setw(25)
         << " ======================================================================================================================\n";
    cout << setfill(' ') << setw(1);
    cout << "|    " << setfill(' ') << setw(2) << "Month " << "   ||  " << setfill(' ') << setw(2)
         << "Opening Balance $ " << "|";
    cout << "|  " << setfill(' ') << setw(2) << "Monthly Deposit $" << "  ||    " << setfill(' ') << setw(3)
         << "Total $ ";
    cout << "||  " << setfill(' ') << setw(2) << "Monthly Interest $" << "  || " << setfill(' ') << setw(2)
         << "Closing Balance $" << "|\n";
    cout << setfill(' ') << setw(25)
         << " ======================================================================================================================\n\n";
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰

// After the user inputs the data, this method is used to display the data inputted by the user
void DisplayInterface::openingMenuVerification() {
    cout << "\n";
    cout << "===============Data Inputted==============\n";
    cout << "The Initial Investment Amount: $" << Bank::GetInitialBalanceAmount() << endl;

    cout << "The Monthly Deposit: $" << Bank::GetMonthlyDepositAmt() << endl;
    cout << "The Annual Interest: " << Bank::GetAnnualInterestRate() << "% Interest" << endl;
    cout << "Years you inputted: " << Bank::GetNumberOfYears() << " years" << endl;

    cout << "==========================================\n";
    cout << "\n\n";

    cout << "Press 1 if information is accurate or Press 2 if you need to make changes.\n";
    while (loop) {
        cin >> choice;

        switch (choice) {
            case 1:
                withoutDepositsMenu();
                depositMenu();
                loop = false;
                break;
            case 2:
                mainMenu();
                loop = false;
                break;
            default:
                cout << "Press 1 if information is accurate or Press 2 if you need to make changes.\n";
                loop = true;
        }
    }
}
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰