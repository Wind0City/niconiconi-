//队列的顺序表示（动态开辟空间方法
//都是理解成循环队列的
#include <stdio.h>
#include <stdlib.h>
typedef struct order_queue
{
    int *val; //动态数组
    int front, tail;
    int maxsize;            //定义队列的长度
    order_queue(int n = 10) //默认开辟十个;
    {
        maxsize = n;
        front = 0;
        tail = 0;
        val = (int *)malloc(sizeof(int) * n);
    }
} oque;
bool isempty(oque &s)
{
    return s.front == s.tail ? true : false; //直接判断是否指向同一个位置
}
bool isfull(oque &s)
{
    return (s.tail + 1) % s.maxsize == s.front; //用尾指针指向的下一个位置是否和头指针相同即可
}
void push(oque &s, int val)
{
    if (isfull(s))
    {
        printf("error!\n");
        exit(1);
    }
    *(s.val + s.tail) = val;           //正常赋值（看作数组赋值也可
    s.tail = (s.tail + 1) % s.maxsize; //更新
}
int pop(oque &s) //弹出操作
{
    if (isempty(s)) //先判空
    {
        printf("queue empty! Can't dequeue.\n");
        return 0;
    }
    int x = *(s.val + s.front);          //把栈顶的拿出来
    s.front = (s.front + 1) % s.maxsize; //再"弹出"
    return x;
}
int front_ele(oque &s) //查询队首元素
{
    if (isempty(s)) //先判空
    {
        printf("error!\n");
        exit(1);
    }
    return *(s.val + s.front); //入队和出队的操作使得front是合理的
}
void clear(oque &s) //清空操作
{
    s.front = s.tail = 0; //判断头尾指针即可
}
void delete_oque(oque &s) //销毁操作
{
    s.front = 0;
    s.tail = 0;
    s.maxsize = 0;
    free(s.val);
}
int get_length(oque &s) //求长度
{
    if (s.tail >= s.front) //分情况套路,要记得一直是尾指针减头指针
    {
        return s.tail - s.front;
    }
    return s.tail + s.maxsize - s.front;
    //这部分分别举例看一下比较好
}
void show(oque &s)
{
    printf("the content of queue is:\n");
    if (s.tail < s.front) //也要分情况而言
    {
        for (int i = 0, j = s.front; i < get_length(s); i++, j++) // i来记录，j用来进行下标操作
        {
            if (j >= s.maxsize)
            {
                j = 0;
            }
            printf("%d ", *(s.val + j));
        }
        printf("\n");
        return;
    }
    //当头指针是小于尾指针的时候
    for (int i = 0, j = s.front; i < get_length(s); i++, j++)//i，j同上
    {
        if (j >= s.maxsize) //是下标始终是合法的
        {
            j = 0;
        }
        printf("%d ", *(s.val + j));
    }
    printf("\n");
}
//测试代码
/* int main()
{
    oque q(20);
    for (int i = 1; i <= 10; i++)
    {
        push(q, 'a' + i);
    }
    while (!isempty(q))
    {
        printf("%c ", pop(q));
    }
    if (isempty(q))
    {
        printf("down!\n");
    }
} */