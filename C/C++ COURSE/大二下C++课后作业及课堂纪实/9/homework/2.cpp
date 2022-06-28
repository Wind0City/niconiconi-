//problem 9-2
#include <iostream>
#include <iomanip>
using namespace std;
class Account
{
protected:
    double balance;

public:
    Account(double money)
    {
        if (money < 0)
        {
            cout << "Initial balance cannot be negative." << endl;
            money = 0;
        }
        balance = money;
    }
    virtual double calculateInterest() { return 0; }
    virtual void credit(double money)
    {
        balance += money;
    }
    virtual bool debit(double money)
    {
        if (money > balance)
        {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        }
        balance -= money;
        return true;
    }
    double getBalance()
    {
        return balance;
    }
};
class SavingsAccount : public Account
{
private:
    double interestrate;

public:
    SavingsAccount(double money, double strate) : Account(money)
    {
        interestrate = strate;
    }
    double calculateInterest()
    {
        double ans = getBalance() * interestrate;
        balance = balance + balance * interestrate;
        return ans;
    }
};
class CheckingAccount : public Account
{
private:
    double transactionFee;

public:
    CheckingAccount(double money, double fee) : Account(money)
    {
        transactionFee = fee;
    }
    void credit(double money)
    {
        cout << "$" << transactionFee << " transaction fee charged." << endl;
        balance = balance + money - transactionFee;
    }
    bool debit(double money)
    {
        if (Account::debit(money))
        {
            if (balance < transactionFee)
            {
                cout << "charge fee amount exceeded account balance." << endl;
                Account::credit(money);
            }
            else
            {
                cout << "$" << transactionFee << " transaction fee charged." << endl;
                balance -= transactionFee;
            }
        }
        else
        {
            cout << "Debit amount exceeded account balance.”" << endl;
        }
        return true;
    }
};
int main()
{
    Account *accounts[4];
    accounts[0] = new SavingsAccount(25.0, 0.03);
    accounts[1] = new CheckingAccount(80.0, 1.0);
    accounts[2] = new SavingsAccount(200.0, 0.015);
    accounts[3] = new CheckingAccount(400.0, 0.5);
    for (int i = 0; i < 4; i++)
    {
        float c, d;
        cin >> c >> d;
        cout << "Account " << i + 1 << " balance: $" << fixed << showpoint << setprecision(2) << accounts[i]->getBalance() << endl;
        Account *p = dynamic_cast<SavingsAccount *>(accounts[i]);
        accounts[i]->debit(c);
        accounts[i]->credit(d);
        if (p != 0)
        {
            cout << "Adding $" << fixed << showpoint << setprecision(2) << p->calculateInterest() << " interest to Account " << i + 1 << " (a SavingsAccount)" << endl;
        }
        cout << "Updated Account " << i + 1 << " balance: $" << fixed << showpoint << setprecision(2) << accounts[i]->getBalance() << "\n\n";
    }
    return 0;
}
