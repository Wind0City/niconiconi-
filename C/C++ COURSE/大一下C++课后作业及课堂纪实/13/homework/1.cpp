//12-1
#include <iostream>
#include <exception>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    try
    {
        if (b == 0)
        {
            throw b;
        }
    }
    catch (double)
    {
        cout << "Attempted to divide by zero!" << endl;
    }
    cout << a / b << endl;
    return 0;   
}