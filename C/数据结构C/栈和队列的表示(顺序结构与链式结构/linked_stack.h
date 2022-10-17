//栈的实现（链式存储方式，首先为了方便，入栈的操作是通过对链表的头插和头删来实现
//为了方便，直接封装成一个类
#include <stdio.h>
#include <stdlib.h>
typedef struct sll //正常的链表节点
{
    char val;
    struct sll *next;
} * node;
struct linkstack //包装为一个栈
{
    int maxsize;
    int size;
    node top; //因为采用的是头插法，所以该指针指向的一直是栈顶元素
};
void init_satck(linkstack &s) //创建/初始化操作
{
    s.maxsize = 100;
    s.size = 0; //正常的大小范围设置
    s.top = (node)malloc(sizeof(struct sll));
    s.top->next = NULL; //创造栈顶点
}
void clear(linkstack &s) //清空栈，表面意义上的清空，清空了，但不完全清空
{
    if (!s.top) //首先这个栈的头节点要存在
    {
        printf("error!\n");
        exit(1);
    }
    s.size = 0;
}
bool isempty(linkstack &s) //判空操作
{
    if (!s.top)
    {
        printf("error!\n");
        exit(1);
    }
    return s.top->next ? false : true; //即判断有没有栈顶元素
    // return s.size>0 ? false :true;(也可以换一种思路)
}
bool isfull(linkstack &s) //判满操作
{
    if (!s.top)
    {
        printf("error!\n");
        exit(1);
    }
    return s.maxsize == s.size ? true : false; //只能用对应的size大小来进行判断
}
void push(linkstack &s, char c)
{
    if (isfull(s) || !s.top) //前提判断
    {
        printf("error!\n");
        exit(1);
    }
    node p = (node)malloc(sizeof(struct sll)); 
    p->val = c;
    p->next = s.top->next;
    s.top->next = p;
    s.size++;
}
char pop(linkstack &s)
{
    if (isempty(s) || !s.top) //特判栈为空的时候
    {
        printf("error!\n");
        exit(1);
    }
    //出栈无非就是链表中删除第一个节点（头插法的特性使得链表的顺序是符合先进后出的
    node p = s.top->next;  //首先把栈顶元素节点记录下来
    s.top->next = p->next; //把top指针指向栈顶元素节点的下一个节点
    char c = p->val;       //记录栈顶元素
    free(p);               //释放空间
    s.size--;
    return c;
}
void delete_stack(linkstack &s) //链式栈的销毁操作要依赖于出栈操作
{
    if (!s.top)
    {
        printf("error!\n");
        exit(1);
    }
    while (!isempty(s)) //不断的出栈操作，因为链式栈的出栈操作也会有对用的释放空间操作
    {
        pop(s);//挨个弹出
    }
    free(s.top); //销毁栈顶指针
}
char top(linkstack &s)
{
    if (!s.top || isempty(s))
    {
        printf("error!\n");
        exit(1);
    }
    return s.top->next->val; //栈顶元素
}
//测试代码
/* int main()
{
    linkstack s;
    init_satck(s);
    for (int i = 0; i < 10; i++)
    {
        push(s, 'a' + i);
    }
    while (!isempty(s))
    {
        printf("%c ", pop(s));
    }
    if (isempty(s))
    {
        printf("down!\n");
    }
} */
//链式栈难点还是链表的各种操作，理解链表之后，链式栈只是对链表的部分操作而已