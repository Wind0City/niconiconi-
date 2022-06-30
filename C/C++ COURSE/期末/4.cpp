#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>
using namespace std;
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