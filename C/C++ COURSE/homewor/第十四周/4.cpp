//12-4
#include <iostream>
#include <exception>
using namespace std;
class MyException
{
public:
    MyException(int x)
    {
        levle = x;
    }
    void Reason()
    {
        cout << "Exception:" << levle << endl;
    }

private:
    int levle;
};
void fn1(int x)
{
    MyException *k;
    MyException l(x);
    k = &l;
    throw k;
}
int main()
{
    int excpNo;
    cin >> excpNo;
    try
    {
        if (excpNo > 3 || excpNo < 1)
            throw 1;
        fn1(excpNo);
    }
    catch (MyException *e)
    {
        e->Reason();
    }
    catch (...)
    {
        cout << "Other error." << endl;
    }
    return 0;
}
