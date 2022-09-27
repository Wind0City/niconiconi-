//双链表的实现以及各种操作
#include <stdio.h>
#include <stdlib.h>
typedef struct sll
{
    int val;
    struct sll *next;
    struct sll *pre; //比单链表多的一个前指针
} * node;            //注意此时的重命名方法是将struct sll这个类型的指针类型重命名为 node
node head, p, last;
void build_wei() //双链表的建立(尾插法)
{
    head = (node)malloc(sizeof(struct sll));
    head->pre = NULL;
    printf("length:");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("the %d_th ele:", i);
        int ss;
        scanf("%d", &ss);
        p = (node)malloc(sizeof(struct sll));
        p->val = ss;
        if (i == 1) //特判第一个元素，在和单链表一样的操作之后加上对前指针的操作
        {
            last = p;
            head->next = last;
            last->next = NULL;
            last->pre = head;
        }
        else //注意赋值顺序，先将上一个节点的next指向当前，再将现在的前指针指向last，再重现将last更新
        {
            last->next = p;
            p->pre = last;
            last = p;
            last->next = NULL;
        }
    }
}
/*
双链表的头插法可以仿照单链表中的头茬法
简而言之，头插法法无非就是将尾插法中重复操作赋值的last换成head
ps：还是手打以便好一点
*/
void show() //遍历输出操作
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
    printf("reverse:"); //通过新增的pre指针从尾部再遍历一遍
    //此时head——new指针是指向了最后一个有实值的节点
    while (head_new && head_new != head) //向前遍历要注意第二个条件，因为head本身只作为一个开头，并没有元素
    {
        printf("%d ", head_new->val);
        head_new = head_new->pre;
    }
    printf("\n");
}
int get_len() //双向链表的长度
{
    int ans = 0;
    node head_new = head;
    while (head_new->next)
    {
        ans++;
        head_new = head_new->next;
    }
    return ans;
}
node find(int i) //查找第i位的指针（遍历即可
{
    int j = 0;
    if (i < 0 || i > get_len())
    {
        return NULL;
    }
    node head_new = head;
    while (j < i && head_new->next)
    {
        head_new = head_new->next;
        j++;
    }
    return head_new;
}
void insert(int x, int i) //双向链表的插入操作
{
    if (i < 0 || i > get_len()) //要对i判断
    {
        printf("error!\n");
        exit(1);
        return;
    }
    //下面的部分纸上画一画更容易理解
    node temp = find(i);
    node ins = (node)malloc(sizeof(struct sll));
    ins->val = x;
    ins->next = temp->next;
    ins->pre = temp;
    if (temp->next) //在这里要判断temp是不是最后一个元素
    {
        temp->next->pre = ins;
    }
    temp->next = ins;
}
void delete_ele(int i)
{
    if (i < 1 || i > get_len())
    {
        printf("delete failed: index is wrong.\n");
        return;
    }
    node temp = find(i - 1);
    node third = temp->next->next;
    free(temp->next);
    temp->next = third;
    if (third) //注意这里要判断删除的节点是不是最后一个
    {
        third->pre = temp;
    }
}
bool isempty()
{
    return head->next ? false : true;
}
void clear() //清空操作，但不完全清空
{
    head->next = NULL;
}
int main()
{
    build_wei();
    show();
    printf("length:%d\n", get_len());
    printf("%d\n", find(3)->val);
    printf("insert 3 int to 5_th\n");
    insert(3, 0);
    show();
    printf("delete the 3_th\n");
    delete_ele(3);
    printf("length :%d\n", get_len());
    show();
    if (!isempty())
    {
        printf("yrs");
    }
}