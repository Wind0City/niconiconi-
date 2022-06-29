//problem 5-1
#include <iostream>
#include <cmath>
using namespace std;
class BankAccount
{
    friend void welcome(BankAccount &p)
    {
        cout << "Welcome to our bank.\n"
             << "The status of your account is:\n";
        cout << "Account balance: $" << p.getBalance() << endl;
        cout << "Rate:" << p.getRate() << "%\n";
    }
    friend bool isLarger(BankAccount &a, BankAccount &b)
    {
        if (a.getBalance() > b.getBalance())
        {
            return true;
        }
        if (a.getBalance() < b.getBalance())
        {
            return false;
        }
        if (a.getRate() > b.getRate())
        {
            return true;
        }
        return false;
    }

public:
    BankAccount(double balance, double rate);

    BankAccount(int dollars, int cents, double rate);

    BankAccount(int dollars, double rate);

    BankAccount();

    void update();

    void input();

    void output();

    double getBalance() const;

    int getDollars() const;

    int getCents() const;

    double getRate() const;

    void setBalance(double balance);

    void setBalance(int dollars, int cents);

    void setRate(double newRate);

private:
    int accountDollars;
    int accountCents;
    double rate;

    int dollarsPart(double amount);
    int centsPart(double amount);
    int round(double number);
    double fraction(double percent);
};
BankAccount::BankAccount(double balance, double rate)
    : accountDollars(dollarsPart(balance)), accountCents(centsPart(balance))
{
    setRate(rate);
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    setBalance(dollars, cents);
    setRate(rate);
}

BankAccount::BankAccount(int dollars, double rate) : accountDollars(dollars), accountCents(0)
{
    setRate(rate);
}

BankAccount::BankAccount() : accountDollars(0), accountCents(0), rate(0.0) {}

void BankAccount::update()
{
    double balance = accountDollars + accountCents * 0.01;
    balance = balance + fraction(rate) * balance;
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
}

void BankAccount::input()
{
    double balanceAsDouble;
    cin >> balanceAsDouble;
    accountDollars = dollarsPart(balanceAsDouble);
    accountCents = centsPart(balanceAsDouble);
    cin >> rate;
    setRate(rate);
}

void BankAccount::output()
{
    int absDollars = abs(accountDollars);
    int absCents = abs(accountCents);
    cout << "Account balance: $";
    if (accountDollars < 0)
        cout << "-";
    cout << absDollars;
    if (absCents >= 10)
        cout << "." << absCents << endl;
    else
        cout << "." << '0' << absCents << endl;

    cout << "Rate: " << rate << "%\n";
}

double BankAccount::getBalance() const
{
    return (accountDollars + accountCents * 0.01);
}

int BankAccount::getDollars() const
{
    return accountDollars;
}

int BankAccount::getCents() const
{
    return accountCents;
}

double BankAccount::getRate() const
{
    return rate;
}

void BankAccount::setBalance(double balance)
{
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
}

void BankAccount::setBalance(int dollars, int cents)
{
    if ((dollars < 0 && cents > 0) || (dollars > 0 && cents < 0))
    {
        cout << "Inconsistent account data.\n";
        exit(1);
    }
    accountDollars = dollars;
    accountCents = cents;
}

void BankAccount::setRate(double newRate)
{
    if (newRate >= 0.0)
        rate = newRate;
    else
    {
        cout << "Cannot have a negative interest rate.\n";
        exit(1);
    }
}

int BankAccount::dollarsPart(double amount)
{
    return static_cast<int>(amount);
}

int BankAccount::centsPart(double amount)
{
    double doubleCents = amount * 100;
    int intCents = (round(fabs(doubleCents))) % 100; //% can misbehave on negatives
    if (amount < 0)
        intCents = -intCents;
    return intCents;
}

int BankAccount::round(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

double BankAccount::fraction(double percent)
{
    return (percent / 100.0);
}

int main()
{
    BankAccount account1(6543.21, 4.5), account2;
    //    cout << "Enter data for account 2:\n";
    account2.input();
    cout << "Account 2:\n";
    welcome(account2);
    cout << "\nAccount 1:\n";
    welcome(account1);
    if (isLarger(account1, account2))
        cout << "\naccount1 is larger.\n";
    else
        cout << "\naccount2 is at least as large as account1.\n";
    return 0;
}
