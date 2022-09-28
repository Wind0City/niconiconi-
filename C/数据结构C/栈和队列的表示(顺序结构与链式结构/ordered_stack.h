//顺序栈的实现
#include <stdio.h>
#include <stdlib.h>
typedef struct ordered_stack
{
    int *QAQ;    //如单链表一样的指向动态数组的第一个指针
    int size;    //栈的长度，出栈以及访问栈顶会需要
    int maxsize; //栈的最大长度（容量
} ostack;
void init_stack(ostack &s) //初始化操作
{
    s.maxsize = 100;
    //默认先将栈的最大容量初始化位100
    s.size = 0;
    //刚开始的栈大小为0
    s.QAQ = (int *)malloc(sizeof(int) * s.maxsize);
    //开辟动态空间
}
void delete_stack(ostack &s) //删除销毁操作
{
    s.maxsize = 0;
    s.size = 0;
    free(s.QAQ);
    return;
}
void clear(ostack &s) //清空栈，并不是删除
{
    if (!s.QAQ) //首先这个栈要没有被销毁
    {
        printf("error!\n");
        exit(1);
    }
    s.size = 0;
}
bool isempty_s(ostack &s) //判空
{
    if (!s.QAQ) //首先这个栈要没有被销毁
    {
        printf("error!\n");
        exit(1);
    }
    return s.size > 0 ? false : true;
}
bool isfull(ostack &s) //判满
{
    if (!s.QAQ) //首先这个栈要没有被销毁
    {
        printf("error!\n");
        exit(1);
    }
    return s.size == s.maxsize ? true : false;
}
void push_s(ostack &s, int c) //入栈操作
{
    if (isfull(s) || !s.QAQ) //判断入栈时是否超出最大容量
    {
        printf("error!\n");
        exit(1);
    }
    *(s.QAQ + s.size) = c; //正常赋值
    s.size++;              //长度要增加
}
int pop_s(ostack &s) //出栈操作
{
    if (isempty_s(s) || !s.QAQ) //特判栈为空的时候
    {
        printf("error!\n");
        exit(1);
    }
    int c = *(s.QAQ + s.size - 1); //要注意size只是代表的大小，真正的栈顶元素应该是*(s.qaq+s.size-1);
    s.size--;                      //出栈了长度要减
    return c;                      //同时为了操作返回栈顶元素
}
int top(ostack &s)
{
    if (isempty_s(s) || !s.QAQ) //特判栈为空的时候
    {
        printf("error!\n");
        exit(1);
    }
    return *(s.QAQ + s.size - 1);
}
//测试代码
/* int main()
{
    ostack mystack;
    init_stack(mystack);
    for (int i = 0; i < 10; i++)
    {
        push(mystack, 'a' + i);
    }
    while (!isempty(mystack))
    {
        printf("%c ", pop(mystack));
    }
    if (isempty(mystack))
    {
        printf("down!\n");
    }
} */
//顺序栈还是比较简单的（bushi