//probelm 6-1
#include <iostream>
using namespace std;
int findG(int a, int b) //最大公约数
{
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    if (a == b)
    {
        return a;
    }
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int r;
    while (1)
    {
        r = a % b;
        if (r == 0)
        {
            return b;
        }
        a = b;
        b = r;
    }
}
int findW(int a, int b) //最小公倍数
{
    if (a == b)
    {
        return a;
    }
    if (a < b)
    {
        int temp = a;
        a = b;
        b = a;
    }
    for (int i = 2;; i++)
    {
        if (b * i % a == 0)
        {
            return b * i;
        }
    }
}
class Rational
{
    friend ostream &operator<<(ostream &out, const Rational &a)
    {
        if (a.denominator == 1)
        {
            out << a.numerator;
        }
        else
        {
            out << a.numerator << "/" << a.denominator;
        }
        return out;
    }
    friend bool operator<(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        if (x >= y)
        {
            return false;
        }
        return true;
    }
    friend bool operator<=(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        if (x > y)
        {
            return false;
        }
        return true;
    }
    friend bool operator>(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        if (x <= y)
        {
            return false;
        }
        return true;
    }
    friend bool operator>=(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        if (x < y)
        {
            return false;
        }
        return true;
    }
    friend bool operator==(const Rational &a, const Rational &b)
    {
        if (a.numerator == b.numerator && a.denominator == b.denominator)
        {
            return true;
        }
        return false;
    }
    friend bool operator!=(const Rational &a, const Rational &b)
    {
        if (a.numerator != b.numerator || a.denominator != b.denominator)
        {
            return true;
        }
        return false;
    }
    friend Rational operator+(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        return Rational(x + y, temp);
    }
    friend Rational operator-(const Rational &a, const Rational &b)
    {
        int temp = findW(a.denominator, b.denominator);
        int x = a.numerator * (temp / a.denominator);
        int y = b.numerator * (temp / b.denominator);
        return Rational(x - y, temp);
    }
    friend Rational operator*(const Rational &a, const Rational &b)
    {
        return Rational(a.numerator * b.numerator, a.denominator * b.denominator);
    }
    friend Rational operator/(const Rational &a, const Rational &b)
    {
        return Rational(a.numerator * b.denominator, a.denominator * b.numerator);
    }

public:
    Rational(int x = 1, int y = 1)
    {
        if (y == 0)
        {
            y = 1;
        }
        if ((x < 0 && y < 0) || (x > 0 && y < 0))
        {
            x = -x, y = -y;
        }
        int temp = findG(x, y);
        numerator = x / temp;
        denominator = y / temp;
    }
    Rational(const Rational &a)
    {
        numerator = a.numerator;
        denominator = a.denominator;
    }

private:
    int numerator;
    int denominator;
};
int main()
{
    int firstN, firstD, secondN, secondD;
    cin >> firstN;
    cin >> firstD;
    cin >> secondN;
    cin >> secondD;
    Rational c(firstN, firstD), d(secondN, secondD), x;
    cout << c;
    cout << " + ";
    cout << d;
    cout << " = ";
    x = c + d; // test overloaded operators + and =
    cout << x;
    cout << '\n';
    cout << c;
    cout << " - ";
    cout << d;
    cout << " = ";
    x = c - d; // test overloaded operators - and =
    cout << x;
    cout << '\n';
    cout << c;
    cout << " * ";
    cout << d;
    cout << " = ";
    x = c * d; // test overloaded operators * and =
    cout << x;
    cout << '\n';
    cout << c;
    cout << " / ";
    cout << d;
    cout << " = ";
    x = c / d; // test overloaded operators / and =
    cout << x;
    cout << '\n';
    cout << c;
    cout << " is:\n"; // test overloaded greater than operator
    cout << ((c > d) ? "  > " : "  <= ");
    cout << d;
    cout << " according to the overloaded > operator\n";
    // test overloaded less than operator
    cout << ((c < d) ? "  < " : "  >= ");
    cout << d;
    cout << " according to the overloaded < operator\n";
    // test overloaded greater than or equal to opera-tor
    cout << ((c >= d) ? "  >= " : "  < ");
    cout << d;
    cout << " according to the overloaded >= operator\n";
    // test overloaded less than or equal to operator
    cout << ((c <= d) ? "  <= " : "  > ");
    cout << d;
    cout << " according to the overloaded <= operator\n";
    // test overloaded equality operator
    cout << ((c == d) ? "  == " : "  != ");
    cout << d;
    cout << " according to the overloaded == operator\n";
    // test overloaded inequality operator
    cout << ((c != d) ? "  != " : "  == ");
    cout << d;
    cout << " according to the overloaded != operator" << endl;
    return 0;
} // end main