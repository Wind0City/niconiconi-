// 11-5
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> a;
    char x[1000];
    int i = 0;
    while ((x[i++] = getchar()) != '\n')
        ;
    for (int j = 0; j < i; j++)
    {
        if (x[j] == '{' || x[j] == '(' || x[i] == '[')
        {
            a.push(x[j]);
        }
        if (x[j] == '}' || x[j] == ')' || x[i] == ']')
        {
            if (a.empty()) //避免出现第一个就是右括号
            {
                cout << "false" << endl;
                return 0;
            }
            a.pop();
        }
    }
    if (a.empty())
    {
        cout << "true" << endl;
    }
    else
    {

        cout << "false" << endl;
    }
    return 0;
}