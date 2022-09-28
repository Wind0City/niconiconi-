#include <stdio.h>
#include <stdlib.h>
typedef struct sll //正常的链表节点
{
    char val;
    struct sll *next;
} * node;
typedef struct linked_queue
{
    node front; //指向队首元素
    node tail;  //指向队尾元素的下一个
    int size;   //记录队列中元素的大小
} lque;
void init_queue(lque &s) //初始化操作
{
    s.front = (node)malloc(sizeof(struct sll));
    s.tail = (node)malloc(sizeof(struct sll));
    s.front->next = NULL;
    s.tail = s.front;
    s.size = 0;
}
//链式队列不可能队满，所以可以不用判断，或者说可以强行给一个值与size比较来进行规范
bool isempty(lque &s)
{
    if (!s.front || !s.tail)
    {
        printf("error!\n");
        exit(1);
    }
    return s.front == s.tail; //即判满的条件是看头节点与尾节点是否为同一个节点
}
void push(lque &s, char e) //入队操作
{
    //不用判满 不用判满 不用判满
    if (!s.front || !s.tail)
    {
        printf("error!\n");
        exit(1);
    }
    node p = (node)malloc(sizeof(struct sll)); //正常创建新节点
    p->val = e;
    p->next = NULL;
    s.tail->next = p; //队列原先的最后一个元素的下一个指向新的节点
    s.tail = p;       //并将尾指针更新为新的节点
    s.size++;         //记得长度要加
}
char pop(lque &s)
{
    if (isempty(s) || !s.front || !s.tail)
    {
        printf("error!\n");
        exit(1);
    }
    node p = s.front->next; //记录要弹出的节点
    char c = p->val;
    s.front->next = p->next; //将头指针指向第二个节点
    if (p == s.tail)         //要判断此时弹出的是不是最后一个元素
    {
        s.tail = s.front;
    }
    free(p); //释放空间
    p == NULL;
    s.size--;
    return c;
}
void clear(lque &s)
{
    if (!s.front || !s.tail)
    {
        printf("error!\n");
        exit(1);
    }
    s.tail = s.front; //直接表面清楚
}
void delete_lque(lque &s)
{
    //技巧但有点懒惰的写法
    while (!isempty(s))
    {
        pop(s);
    }
    free(s.front);
    free(s.tail);
    s.size = 0;
}
//测试代码
/* int main()
{
    lque q;
    init_queue(q);
    for (int i = 1; i < 10; i++)
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