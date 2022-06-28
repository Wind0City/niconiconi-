//12-2
#include <iostream>
#include <exception>
#include <string>
using namespace std;
void f2()
{
    cout << "In f2 function" << endl;
    string x("hello");
    throw x;
}
int f1(int a, int b)
{

    try
    {
        if (b == 0)
        {
            throw a;
        }
        f2();
    }
    catch (string)
    {
        cout << "Exception from f2" << endl;
    }
    return a % b;
}
int main()
{
    float x, y;
    cin >> x >> y;
    try
    {
        if (x != (int)x || y != (int)y)
        {
            throw 1.20;
        }
        x = int(x), y = int(y);
        int ans = f1(x, y);
        cout << x << "%" << y << "=" << ans << endl;
        cout << "In f1 function" << endl;
    }
    catch (int)
    {
        cout << "You inputted:0" << endl;
    }
    catch (double)
    {
        cout << "Non-int was inputted, try again" << endl;
    }
    cout << "In main function" << endl;
    return 0;
}
