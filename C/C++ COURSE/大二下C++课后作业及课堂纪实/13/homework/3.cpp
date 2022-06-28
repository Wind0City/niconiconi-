//12-3
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class MyString
{
public:
    MyString(long m)
    {
        if (m > 8192)
        {
            throw 'c';
        }
        string x;
        cin >> x;
        a = x;
        cout << "Constructing..." << endl;
        cout << "Construction finished." << endl;
    }
    void ShowStr()
    {
        cout << a << endl;
    }

private:
    string a;
};
int main()
{
    long a;
    cin >> a;
    try
    {
        if (a > 0)
        {
            MyString strl1(a);
            strl1.ShowStr();
        }
        else
        {
            char *c = "Array length error.";
            throw c;
        }
    }
    catch (char *c)
    {
        cout << c << endl;
    }
    catch (char)
    {
        cout << "Constructor abnormal" << endl;
    }
    catch (...)
    {
        cout << "Other failures." << endl;
    }
    cout << "Main finished." << endl;
    return 0;
}