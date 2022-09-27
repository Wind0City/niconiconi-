//单链表的相关操作
#include <stdio.h>
#include <stdlib.h>
typedef struct sll
{
    int val;
    struct sll *next;
} * node;           //注意此时的重命名方法是将struct sll这个类型的指针类型重命名为 node
node head, last, p; //头指针，尾节点，赋值节点
//单链表的创建
void build_wei() //尾插法建立单链表（不带头节点
{
    head = (node)malloc(sizeof(struct sll));
    printf("length:");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("the %d_th ele:", i);
        int ss;
        scanf("%d", &ss);
        p = (node)malloc(sizeof(struct sll)); //首先动态开辟空间，创建一个新节点
        p->val = ss;                          //节点值更新
        if (i == 1)                           //特判第一个元素，是将head的next指向当前节点
        {
            last = p;
            head->next = last;
            last->next = NULL;
        }
        else //正常情况的更新
        {
            last->next = p;    //此时的last代表的上一个节点，将上个节点的next指向当前新节点
            last = p;          //将last更新为最新的last节点
            last->next = NULL; //尾节点更新
        }
    }
}
void build_tou() //头插法建立单链表（不带头节点
{
    head = (node)malloc(sizeof(struct sll));
    printf("length:");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("the %d_th ele:", i);
        int ss;
        scanf("%d", &ss);
        p = (node)malloc(sizeof(struct sll)); //首先动态开辟空间，创建一个新节点
        p->val = ss;                          //节点值更新
        if (i == 1)                           //特判第一个元素，是将head的next指向当前节点
        {
            last = p;
            head->next = last;
            last->next = NULL;
        }
        else //正常情况的更新
        {
            head->next = p; //将新节点指定为head的下一个节点
            p->next = last; //新节点的next指向上一个节点，即将新节点夹在原来的链表head后面
            last = p;       //重新赋值
        }
    }
}
void show() //单链表的遍历
{
    node head_new;
    head_new = head;
    printf("ele:");
    while (head_new->next)
    {
        printf("%d ", head_new->next->val);
        head_new = head_new->next;
    }
    printf("\n");
}
int get_len() //遍历法求单链表的长度
{
    int ans = 0;
    node head_new;
    head_new = head;
    while (head_new->next)
    {
        ans++;
        head_new = head_new->next;
    }
    return ans;
}
node find(int i) //查找第i位的指针
{
    if (i < 0 || i > get_len()) //要对i判断
    {
        return NULL;
    }
    int j = 0;
    node head_new;
    head_new = head;
    while (j < i && head_new->next)
    {
        head_new = head_new->next;
        j++;
    }
    return head_new;
}
void insert(int x, int i) //插入操作，将x插入链表的第i个位置
{
    if (i < 1 || i > get_len()) //要对i判断
    {
        printf("error!\n");
        exit(1);
        return;
    }
    node temp = find(i);
    node ins = (node)malloc(sizeof(struct sll));
    ins->val = x;
    ins->next = temp->next;
    temp->next = ins;
}
//上述三种操作都是遍历进行操作
void delete_ele(int i) //删除操作，删除链表的第i个位置
{
    if (i < 1 || i > get_len())
    {
        printf("delete failed: index is wrong.\n");
        return;
    }
    node temp = find(i - 1);       //找到删除节点的前驱节点
    node third = temp->next->next; //记录删除节点的next
    free(temp->next);              //删除指定节点
    temp->next = third;            //将删除节点的前驱节点的next指向删除节点的next
}
bool isempty() //朴素判断链表是否为空，直接判断head的next是不是空指针
{
    return head->next ? false : true;
}
int main()
{
    build_wei();
    show();
    printf("length :%d\n", get_len());
    printf("the 3_th :%d\n", find(3)->val);
    printf("insert 3 int to 5_th\n");
    insert(3, 5);
    printf("length :%d\n", get_len());
    show();
    printf("delete the 3_th\n");
    delete_ele(3);
    printf("length :%d\n", get_len());
    show();
    if (isempty())
    {
        printf("yrs");
    }
}