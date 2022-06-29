//11-1
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
bool judge(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            a.push_back(2);
            continue;
        }
        if (judge(i))
        {
            a.push_back(i);
        }
    }
    vector<int>::iterator it;
    int y = 0;
    for (it = a.begin(); it != a.end(); it++, y++)
    {
        cout << setw(5) << *it;
        if ((y + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
    return 0;
}