//problem 5-4
#include <iostream>
#include <iomanip>
using namespace std;
class SavingsAccount
{
public:
    SavingsAccount(double x = 0) : savingBalance(x) {}
    void calculateMonthlyInterest()
    {
        savingBalance = savingBalance + savingBalance * annualInterestRate / 12;
    }
    void printBalance()
    {
        cout << "$" << setprecision(2) << std::fixed << savingBalance;
    }
    static void modifyInterestRate(double x)
    {
        annualInterestRate = x;
    }

private:
    double savingBalance;
    static double annualInterestRate;
};
double SavingsAccount::annualInterestRate = 0;
int main()
{
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);
    SavingsAccount::modifyInterestRate(.03);
    // change interest rate
    cout << "Initial balances:\nSaver 1: ";
    saver1.printBalance();
    cout << "\tSaver 2: ";
    saver2.printBalance();
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "\n\nBalances after 1 month's interest applied at .03:\n"
         << "Saver 1: ";
    saver1.printBalance();
    cout << "\tSaver 2: ";
    saver2.printBalance();
    SavingsAccount::modifyInterestRate(.04);
    // change interest rate
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "\n\nBalances after 1 month's interest applied at .04:\n"
         << "Saver 1: ";
    saver1.printBalance();
    cout << "\tSaver 2: ";
    saver2.printBalance();
    cout << endl;
    return 0;
}