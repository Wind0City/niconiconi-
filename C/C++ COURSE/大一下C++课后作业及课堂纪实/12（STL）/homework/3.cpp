//11-3
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    stack<int> a;
    int n;
    cin >> n;
    while (n > 0)
    {
        a.push(n % 2);
        n = n / 2;
    }
    while (!a.empty())
    {
        cout << a.top();
        a.pop();
    }
    return 0;
}