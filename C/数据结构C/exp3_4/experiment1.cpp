#include "D:\\code\\CorC++\\study\\DATA_S\\stack_and_deque\\linked_stack.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    for (int j = 0;; j++)
    {
        string choice;
        printf("Do you want to test again(y or n):");
        cin >> choice;
        if (choice == "y")
        {
            int temp = 1;
            printf("please enter parenthess:");
            string ss;
            cin >> ss;
            linkstack qq;
            init_satck(qq);
            for (int i = 0; i < ss.size(); i++)
            {
                if (ss[i] == '(')
                {
                    push(qq, '(');
                }
                if (ss[i] == ')')
                {
                    if (isempty(qq))
                    {
                        temp = 0;
                        break;
                    }
                    if (top(qq) == '(')
                    {
                        pop(qq);
                    }
                }
            }
            if (temp == 0 || !isempty(qq))
            {
                printf("Not Match!\n");
                continue;
            }
            if (isempty(qq))
            {
                printf("Match!\n");
            }
            delete_stack(qq);
        }
        else
        {
            break;
        }
    }
}