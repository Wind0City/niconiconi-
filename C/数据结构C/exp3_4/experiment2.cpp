#include "D:\\code\\CorC++\\study\\DATA_S\\stack_and_deque\\order_queue.h"
int main()
{
    oque q(5);
    int yl;
    printf("Please enter some numbers, end with 0:");
    int a[10005];
    for (int i = 0;; i++)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            yl = i;
            break;
        }
        else
        {
            a[i] = n;
        }
    }
    printf("Now , the MAXQSIZE of queue is 5\n");
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
        if (a[i] < 0)
        {
            if (isempty(q))
            {
                printf("queue empty!  Can't dequeue\n");
            }
            else
            {
                printf("%d enqueue\n", pop(q));
            }
        }
    }
}