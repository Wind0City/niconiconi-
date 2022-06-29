// 11-8
#include <iostream>
#include <iterator>
using namespace std;
class MyLess
{
public:
    bool operator()(int a1, int a2)
    {
        if ((a1 % 10) < (a2 % 10))
        {
            return true;
        }
        return false;
    }
};
bool MyCompare(int a1, int a2)
{
    if ((a1 % 10) < (a2 % 10))
    {
        return false;
    }
    return true;
}
template <class t, class x>
t *MyMax(t *a, t *b, x op)
{
    int i = 0, j;
    for (i = 0; i < b - a - 1; i++)
    {
        for (j = 0; j < b - a - 1; j++)
        {
            if (op(*(a + j), *(a + j + 1)))
            {
                t temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
    return a;
}

int main()
{
    int a[] = {35, 7, 13, 19, 12};
    cout << *MyMax(a, a + 5, MyLess()) << endl;
    cout << *MyMax(a, a + 5, MyCompare) << endl;
    return 0;
}