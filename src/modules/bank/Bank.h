//=============================================
// Name of App : CS_210_AirgeadBanking
// Date        : Feb 2nd, 2022
// Class       : CS-210
// Author      : Jose Martinez
//=============================================
#ifndef AIRGEADBANKING_BANK_H
#define AIRGEADBANKING_BANK_H
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
// Created a class bank with getters and setters
class Bank {
private:
    double initialBalanceAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;
public:
    void SetInitialBalanceAmount(double initialInvestment);
    void SetMonthlyDeposit(double deposit);
    void SetAnnualInterest(double interest);
    void SetNumYears(int years);
    double GetInitialBalanceAmount() const;
    double GetMonthlyDepositAmt() const;
    double GetAnnualInterestRate() const;
    int GetNumberOfYears() const;
    int yearsToMonths() const;
};
// ⚫️⚫️☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰☰
#endif //AIRGEADBANKING_BANK_H
