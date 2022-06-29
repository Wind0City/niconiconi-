#include <iostream>
using namespace std;
class Account
{
public:
    Account(int = 0, double = 0);
    // constructor sets attributes构造函数
    double getAvailableBalance() const;
    // returns available balance获取余额
    int getAccountNumber() const;
    // returns account number获取账号
    void credit(double);
    // adds an amount to the Account balance存款
    void debit(double amount);
    //取款
private:
    int accountNumber;
    // account number账号
    double availableBalance;
    //余额
};
