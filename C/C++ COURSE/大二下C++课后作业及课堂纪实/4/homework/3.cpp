//Problem 4-3
#include <iostream>
using namespace std;
class A
{
public:
    int val;
    A(int i = 0) : val(i) {}
    int &GetObj()
    {
        return val;
    }
};
int main()
{
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}