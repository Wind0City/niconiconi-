// 11-7
#include <iostream>
#include <map>
#include <iterator>
#include <cmath>
using namespace std;
map<int, int> x;
int main()
{
    int t, m, n;
    cin >> t;
    x[1] = 10000000;
    while (t--)
    {
        cin >> m >> n;
        x[m] = n;
    }
    map<int, int>::iterator it;
    for (it = ++x.begin(); it != x.end(); it++)
    {
        int ans = -10000000;
        int num = it->first;
        cout << it->first << " ";
        map<int, int>::iterator it0;
        if (it->first == 2)
        {
            cout << 1 << endl;
            continue;
        }
        for (it0 = ++x.begin(); it0 != x.end(); it0++)
        {
            if (it0 == it)
            {
                continue;
            }
            if (ans < (it->second - it0->second))
            {
                ans = it->second - it0->second;
                num = it0->first;
            }
        }
        cout << num << endl;
    }
    return 0;
}