//problem 10-4
#include <iostream>
using namespace std;
template <class T>
bool isEqualTo(T a, T b)
{
    return (a == b) ? true : false;
}
class SomeClass
{
    friend ostream &operator<<(ostream &out, SomeClass &a)
    {
        out << "(" << a.geta() << "," << a.getb() << ")";
        return out;
    }
    friend istream &operator>>(istream &in, SomeClass &a)
    {
        double x, y;
        in >> x >> y;
        a.seta(x);
        a.setb(y);
        return in;
    }

public:
    SomeClass(double x = 0, double y = 0) : a(x), b(y) {}
    void seta(double a)
    {
        this->a = a;
    }
    double geta()
    {
        return a;
    }
    void setb(double b)
    {
        this->b = b;
    }
    double getb()
    {
        return b;
    }
    bool operator==(SomeClass &temp)
    {
        return (this->a == temp.a && this->b == temp.b) ? true : false;
    }

private:
    double a, b;
};
int main()
{
    int a; // integers used for
    int b; // testing equality

    // test if two ints input by user are equal
    //    cout << "Enter two integer values: ";
    cin >> a >> b;

    char c; // chars used for
    char d; // testing equality

    // test if two chars input by user are equal
    //    cout << "\nEnter two character values: ";
    cin >> c >> d;

    double e; // double values used for
    double f; // testing equality

    // test if two doubles input by user are equal
    //    cout << "\nEnter two double values: ";
    cin >> e >> f;

    SomeClass g(1, 1.1); // SomeClass objects used
    SomeClass h;         // for testing equality

    cin >> h;

    cout << a << " and " << b << " are "
         << (isEqualTo(a, b) ? "equal" : "not equal") << '\n';

    cout << c << " and " << d << " are "
         << (isEqualTo(c, d) ? "equal" : "not equal") << '\n';

    cout << e << " and " << f << " are "
         << (isEqualTo(e, f) ? "equal" : "not equal") << '\n';

    // test if two SomeClass objects are equal
    // uses overloaded << operator

    cout << "The class objects " << g << " and " << h << " are "
         << (isEqualTo(g, h) ? "equal" : "not equal") << '\n';
    return 0;

} // end main
