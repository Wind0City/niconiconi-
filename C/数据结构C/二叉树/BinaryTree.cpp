//二叉树相关基本操作
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef struct bTree
{
    int ele; //数据
    struct bTree *lchild;
    struct bTree *rchild; //左右结点指针
} * tr;
tr buildtree() //递归建树
{
    tr T; //先建立一个节点
    int data;
    scanf("%d", &data); //输入数据
    if (data == -1)     //-1时建树失败
    {
        return NULL;
    }
    else
    {
        T = (tr)malloc(sizeof(struct bTree)); //分配内存空间
        T->ele = data;
        printf("the lson of %d :", data);
        T->lchild = buildtree(); //递归建立左节点
        printf("the rson of %d :", data);
        T->rchild = buildtree(); //递归建立右节点
        return T;
    }
}
//四种遍历方式(递归方式)
void xianxuBL(tr T) //先序遍历(理解成dfs),一条路走到底
{
    if (T == NULL)
    {
        return;
    }
    printf("%d ", T->ele);
    xianxuBL(T->lchild); //先左
    xianxuBL(T->rchild); //后右
}
void zhongxuBL(tr T)
{
    if (T == NULL)
    {
        return;
    }
    zhongxuBL(T->lchild);  //先一路到底到左节点
    printf("%d ", T->ele); //注意此刻的输出顺序
    zhongxuBL(T->rchild);  //最后再有右边
    //此处还是建议手画理解
}
void houxuBL(tr T)
{
    if (T == NULL)
    {
        return;
    }
    houxuBL(T->lchild);
    houxuBL(T->rchild); //先遍历完节点
    printf("%d ", T->ele);
}
queue<tr> q;        // bfs相关在acm模板里有详细解释
void cengciBL(tr T) //其实就是bfs,这里用队列来实现一下
{
    q.push(T);
    while (!q.empty())
    {
        tr Now = q.front();
        q.pop();
        printf("%d ", Now->ele);
        if (Now->lchild != NULL)
        {
            q.push(Now->lchild);
        }
        if (Now->rchild != NULL)
        {
            q.push(Now->rchild);
        }
    }
}
//不难发现三种遍历方式的规律：
//先序是先输出后遍历，所以会从根节点开始输出，递归遍历输出左子树，回来后再输出右子树
//中序是先遍历一个子节点在输出，理解成从根节点出发，遍历到最左边之后，从最左边的子树开始往回输出
//后序则是先左右遍历（当然左右先分前后），理解成到一个叶子节点后输出该节点，再剪掉叶子节点，往回输出叶子节点
//层次就是bfs(广度优先搜索)
//三种递归方式(用栈的方法)
void xianxuBL1(tr T) //栈方法实现先序遍历
{
    stack<tr> l;
    while (!l.empty() || T != NULL) //非空的时候
    {
        for (; T != NULL; T = T->lchild) //一直向左子节点遍历
        {
            l.push(T);             //入栈
            printf("%d ", T->ele); //先输出(先序遍历的特点)
        }
        //当遍历到子没有左子节点(到头)
        for (; T == NULL && !l.empty(); T = T->rchild)
        {
            T = l.top();
            l.pop();
        } //右子节点不为空持续出栈
    }
    printf("\n");
}
void zhongxuBL1(tr T) //栈方法实现中序遍历
{
    stack<tr> l; //和先序遍历相同的思路，改变了输出位置
    while (!l.empty() || T != NULL)
    {
        for (; T != NULL; T = T->lchild)
        {
            l.push(T);
        }
        for (; T == NULL && !l.empty(); T = T->rchild)
        {
            T = l.top();
            l.pop();
            printf("%d ", T->ele);
        }
    }
    printf("\n");
}
void houxuBL1(tr T) //后序遍历的栈写法
{
    stack<tr> l1;
    stack<tr> l2;
    while (!l1.empty() || T != NULL)
    {
        for (; T != NULL; T = T->rchild)
        {
            l1.push(T);
            l2.push(T);
        }
        for (; T == NULL && !l1.empty(); T = T->lchild)
        {
            T = l1.top();
            l1.pop();
        }
    }
    while (!l2.empty())
    {
        printf("%d ", l2.top()->ele);
        l2.pop();
    }
    printf("\n");
}
//画图！
int main()
{
    tr S;
    printf("the first ele:");
    S = buildtree();
    printf("1.xianxu:\n");
    xianxuBL(S);
    printf("\n1-s.xinaxu\n");
    xianxuBL1(S);
    printf("\n2.zhongxu\n");
    zhongxuBL(S);
    printf("\n2-s.zhongxu\n");
    zhongxuBL1(S);
    printf("\n3.houxu\n");
    houxuBL(S);
    printf("\n3-s.houxu\n");
    houxuBL1(S);
    printf("\n4.cengci\n");
    cengciBL(S);

    return 0;
}