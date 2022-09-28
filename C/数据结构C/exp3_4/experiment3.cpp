#include "D:\\code\\CorC++\\study\\DATA_S\\stack_and_deque\\ordered_stack.h"
#include "D:\\code\\CorC++\\study\\DATA_S\\stack_and_deque\\order_queue.h"
int main()
{
    oque q(5);
    int yl;
    printf("Now , the MAXQSIZE of queue is 5\n");
    printf("Please enter some numbers, end with -1:");
    int a[10005];
    for (int i = 0;; i++)
    {
        int n;
        scanf("%d", &n);
        if (n == -1)
        {
            yl = i;
            break;
        }
        else
        {
            a[i] = n;
        }
    }
    for (int i = 0; i < yl; i++)
    {
        if (a[i] > 0)
        {
            if (isfull(q))
            {
                printf("queue full! %d can't enQueue.\n", a[i]);
                continue;
            }
            push(q, a[i]);
            printf("%d enqueue\n", a[i]);
        }
    }
    show(q);
    ordered_stack p;
    init_stack(p);
    while (!isempty(q))
    {
        printf("%d dequeue,and push stack\n", front_ele(q));
        push_s(p, front_ele(q));
        pop(q);
    }
    while (!isempty_s(p))
    {
        printf("%d pop from stack,and enter the queue\n", top(p));
        push(q, top(p));
        pop_s(p);
    }
    show(q);
}
