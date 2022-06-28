//problem 3-2
#include <iostream>
using namespace std;
class Triangle
{
private:
    double len1, len2, len3;

public:
    Triangle(double x, double y, double z)
    {
        setlen1(x);
        setlen2(y);
        setlen3(z);
    }
    void setlen1(double x1)
    {
        if (x1 < 0)
        {
            x1 = 0;
        }
        len1 = x1;
    }
    void setlen2(double x1)
    {
        if (x1 < 0)
        {
            x1 = 0;
        }
        len2 = x1;
    }
    void setlen3(double x1)
    {
        if (x1 < 0)
        {
            x1 = 0;
        }
        len3 = x1;
    }
    double getlen1()
    {
        return len1;
    }
    double getlen2()
    {
        return len2;
    }
    double getlen3()
    {
        return len3;
    }
    bool isEquilateral()
    {
        if (len1 == len2 && len2 == len3)
        {
            return true;
        }
        else
            return false;
    }
    bool isRightTriangle()
    {
        double len1_2 = len1 * len1, len2_2 = len2 * len2, len3_2 = len3 * len3;
        double temp = max(len1_2, max(len2_2, len3_2));
        double mm = len1_2 + len2_2 + len3_2;
        if ((mm - temp) == temp)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{
    double first, second, third;
    //    cout<<"Enter side one:";
    cin >> first;
    //    cout<<"Enter side two:";
    cin >> second;
    //    cout<<"Enter side three:";
    cin >> third;
    Triangle tri(first, second, third);
    if (tri.isEquilateral())
        cout << "You created an equilateral triangle!" << endl;
    else if (tri.isRightTriangle())
        cout << "You created an right triangle!" << endl;
    else
        cout << "Neither an equilateral nor a right triangle!" << endl;
    return 0; // indicates successful termination
} // end function main