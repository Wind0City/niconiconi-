// 11-5
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> a, b, c;
    char x[1000];
    int i = 0;
    while ((x[i++] = getchar()) != '\n')
        ;
    for (int j = 0; j < i; j++)
    {
        if (x[j] == '{')
            a.push(x[j]);
        if (x[j] == '(')
            b.push(x[j]);
        if (x[j] == '[')
            c.push(x[j]);
        if (x[j] == '}')
        {
            if (a.empty()) //避免第一个是右括号
            {
                cout << "false" << endl;
                return 0;
            }
            a.pop();
        }
        if (x[j] == ')')
        {
            if (b.empty()) //避免第一个是右括号
            {
                cout << "false" << endl;
                return 0;
            }
            b.pop();
        }
        if (x[j] == ']')
        {
            if (c.empty()) //避免第一个是右括号
            {
                cout << "false" << endl;
                return 0;
            }
            c.pop();
        }
    }
    if (a.empty() && b.empty() && c.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
