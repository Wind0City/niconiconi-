// problem 8-1
#include <iostream>
#include <iomanip>
using namespace std;
class Account
{
public:
    Account(int x, double y);
    Account(Account &a)
    {
        accountNumber = a.accountNumber;
        availableBalance = a.availableBalance;
    }
    double getAvailableBalance() const;
    int getAccountNumber() const;
    void credit(double money);
    void debit(double amount);

private:
    int accountNumber;
    double availableBalance;
};
Account::Account(int x = 0, double y = 0) : accountNumber(x), availableBalance(y) {}
double Account::getAvailableBalance() const
{
    return availableBalance;
}
int Account::getAccountNumber() const
{
    return accountNumber;
}
void Account::credit(double money)
{
    availableBalance += money;
}
void Account::debit(double amount)
{
    if (availableBalance < amount)
    {
        cout << "your availablebalance isn't enough\n";
        return;
    }
    availableBalance -= amount;
}
class BankDatabase
{
public:
    BankDatabase(int arraysize);
    ~BankDatabase();
    BankDatabase(BankDatabase &a)
    {
        this->accounts = new Account[a.size];
        this->size = a.size;
    }
    double getAvailableBalance(int accountNumber) const;
    void credit(int accountNumber, double amount);
    Account *getAccount(int accountNumber) const;
    void debit(int userAccountNumber, double amount);
    void show();

private:
    Account *accounts;
    int size;
};
BankDatabase::BankDatabase(int arraysize)
{
    accounts = new Account[arraysize];
    size = arraysize;
    for (int i = 0; i < size; i++)
    {
        int num;
        double temp;
        cin >> num >> temp;
        Account a(num - 1, temp);
        accounts[i] = a;
    }
}
BankDatabase::~BankDatabase()
{
    delete[] accounts;
}
double BankDatabase::getAvailableBalance(int accountNumber) const
{
    Account *p = getAccount(accountNumber);
    if (p == nullptr)
    {
        cout << "Can't finded" << endl;
        return 0;
    }
    return p->getAvailableBalance();
}
void BankDatabase::credit(int accountNumber, double amount)
{
    Account *p = getAccount(accountNumber);
    if (p == nullptr)
    {
        cout << "Can't finded" << endl;
        return;
    }
    p->credit(amount);
}
Account *BankDatabase::getAccount(int accountNumber) const
{
    if (accountNumber - 1 < 0 && accountNumber - 1 >= size)
    {
        return nullptr;
    }
    int answer;
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == accountNumber)
        {
            answer = i;
            break;
        }
    }
    return &accounts[answer];
}
void BankDatabase::debit(int userAccountNumber, double amount)
{
    Account *p = getAccount(userAccountNumber);
    if (p == nullptr)
    {
        cout << "Can't finded" << endl;
        return;
    }
    p->debit(amount);
}
void BankDatabase::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "No." << i << setw(10) << "balance" << endl;
        cout << "----------------" << endl;
        cout << accounts[i].getAccountNumber() << setw(8) << accounts[i].getAvailableBalance() << endl;
    }
}
class Transaction
{
public:
    Transaction(int userAccountNumber, BankDatabase &atmBD);
    int getAccountNumber() const;          // return accountnumber
    BankDatabase &getBankDatabase() const; // returnreference to database
    void execute()
    {
        cout << "账户信息:" << endl;
        cout << " -账号: " << accountNumber << endl;
        cout << " -余额: " << bankDatabase.getAvailableBalance(accountNumber) << endl;
    }

protected:
    int accountNumber;          // indicates account involved
    BankDatabase &bankDatabase; // reference to theaccount info database
};                              // end class Transaction
Transaction::Transaction(int userAccountNumber, BankDatabase &atmBD) : bankDatabase(atmBD)
{
    accountNumber = userAccountNumber;
}
int Transaction::getAccountNumber() const
{
    return accountNumber;
}
BankDatabase &Transaction::getBankDatabase() const
{
    return bankDatabase;
}
class BalanceInquiry : public Transaction
{
public:
    BalanceInquiry(int num, BankDatabase &a) : Transaction(num, a) {}
};
class Deposit : public Transaction
{
public:
    Deposit(int num, BankDatabase &a) : Transaction(num, a)
    {
        double money;
        cin >> money;
        amount = money;
        a.credit(accountNumber, money);
    }

private:
    double amount;
};
int main()
{
    int numberofaccount, currentAccountNumber;
    cin >> numberofaccount;
    BankDatabase db(numberofaccount);
    cin >> currentAccountNumber;
    Deposit *tempDep;
    tempDep = new Deposit(currentAccountNumber, db);
    tempDep->execute();
    BalanceInquiry *tempBal;
    tempBal = new BalanceInquiry(currentAccountNumber, db);
    tempBal->execute();
}
