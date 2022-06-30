#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>
using namespace std;
const int date1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年的各个月份的天数
const int date2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //如年的各个月份的天数
bool judge(int x)                                                       //判断年份是否是闰年
{
    if (x % 400 == 0)
    {
        return true;
    }
    else
    {
        if (x % 4 == 0 && x % 100 != 0)
        {
            return true;
        }
        else
            return false;
    }
}
class Date
{
protected:
    int Year, Month;

public:
    Date(int m = 0, int y = 0)
    {
        Year = y;
        if (m <= 0)
        {
            m = 1;
        }
        if (m > 12)
        {
            m = 12;
        }
        Month = m;
    }
    int getyear() const
    {
        return Year;
    }
    int getmonth() const
    {
        return Month;
    }
};
class Book
{
protected:
    string name;
    double price;

public:
    Book(string nam, double pric) : name(nam), price(pric) {}
    virtual void print()
    {
        cout << "\t\t" << name << "\t\t" << price << "\t\t" << price << endl;
    }
};
class DiscountBook : public Book
{
private:
    double discount;

public:
    DiscountBook(string nam, double pric, double discoun) : Book(nam, pric), discount(discoun) {}
    void print()
    {
        cout << "\t\t" << name << "\t\t" << price << "\t\t" << price * discount << endl;
    }
};
class SellBook : public Book
{
private:
    double total;

public:
    SellBook(string nam, double pric, double tota) : Book(nam, pric), total(tota) {}
    void print()
    {
        double money;
        if (total < 1000)
        {
            money = price * 0.8;
        }
        if (total >= 1000 && total <= 5000)
        {
            money = price * 0.6;
        }
        if (total > 5000)
        {
            money = price * 0.4;
        }

        cout << "\t\t" << name << "\t\t" << price << "\t\t" << money << endl;
    }
};
class datebook : public Book
{
private:
    Date kk;

public:
    datebook(string nam, double pric, int year, int month) : Book(nam, pric), kk(month, year) {}
    void print()
    {
        double money;
        if (kk.getyear() <= 2021 && kk.getmonth() <= 6)
        {
            money = price * 0.95;
        }
        else
        {
            if (kk.getmonth() >= 6)
            {
                money = (1 - (kk.getyear() - 2021) * 0.05) * price;
            }
            if (kk.getmonth() < 6)
            {
                money = (1 - (kk.getyear() - 2021 - 1) * 0.05) * price;
            }
        }
        cout << "\t\t" << name << "\t\t" << price << "\t\t" << money << endl;
    }
};
class BookManager
{
private:
    vector<Book *> mine;

public:
    void add(Book *a)
    {
        mine.push_back(a);
    }
    void printAll()
    {
        cout << "\t\t书名\t\t原价\t\t销售价" << endl;
        vector<Book *>::iterator it;
        for (it = mine.begin(); it != mine.end(); it++)
        {
            (*it)->print();
        }
    }
};

// StudybarCommentBegin
int choice()
{
    int n;
    do
    {
        cin >> n;
    } while (n < 0 || n > 3);
    return n;
}
int main()
{
    BookManager bm; // BookManager类存放指向所有图书的指针
    int n;
    string name;
    double price, discount;
    int total, year, month;
    while ((n = choice()))
    {
        switch (n)
        {
        case 1:
            cin >> name >> price;
            bm.add(new Book(name, price));
            break;
        case 2:
            cin >> name >> price >> discount;
            bm.add(new DiscountBook(name, price, discount));
            break;
        case 3:
            cin >> name >> price >> total;
            bm.add(new SellBook(name, price, total));
            break;
        }
    }
    bm.printAll();
}
// StudybarCommentEnd