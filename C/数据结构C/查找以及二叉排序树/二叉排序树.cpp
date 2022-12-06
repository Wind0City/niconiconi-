/* 二叉排序树的相关，前提是概念已经清晰 */
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
} kt;
typedef struct node // 二叉链表作为存储结构
{
    kt key;
    struct node *lson, *rson;
} bstnode, *bstree;
bstree insterbst(bstree bst, kt key) // 二叉排序树的节点插入
{
    bstree s;        // 先申请一个指针
    if (bst == NULL) // 如果这个根节点还没有(即树还不存在)
    {
        s = (bstree)malloc(sizeof(bstnode));
        s->key = key;
        s->lson = NULL;
        s->rson = NULL;
        bst = s; // 创建节点并且将这个节点作为树根节点
    }
    else
    {
        if (key.key < bst->key.key) // 如果比数根节点小，往左子树走
        {
            bst->lson = insterbst(bst->lson, key); // 递归创建
        }
        if (key.key > bst->key.key) // 如果比数根节点大，往右子树走
        {
            bst->rson = insterbst(bst->rson, key); // 递归创建
        }
    }
    return bst;
}
void create(bstree root, kt *ele, int n) // 二叉排序树的构造(根据一个顺序表来创建)
{
    root = NULL;
    int i = 0;
    while (i < n)
    {
        insterbst(root, ele[i++]);
    }
}
bstree searchbst(bstree root, kt key) // 二叉排序树的查找，因为二叉排序树的特点，类似于二分查找
{
    bstree q;
    q = root;
    while (q != NULL)
    {
        printf("loc.key: %d\n", q->key.key); // 输出路径
        if (q->key.key == key.key)
        {
            return q;
        }
        if (q->key.key > key.key)
        {
            q = q->lson;
        }
        else
        {
            q = q->rson;
        }
    }
    return NULL; // 查找失败
}
void delete_bst(bstree root, kt key) // 二叉排序树的删除
{
    // 待更新
}
bstree build_with_dfs() // 根据输入的扩展的先序遍历序列，建立二叉排序树
{
    bstree T;
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    else
    {
        T = (bstree)malloc(sizeof(bstnode));
        T->key.key = data;
        printf("the lson of %d :", data);
        T->lson = build_with_dfs(); // 递归建立左节点
        printf("the rson of %d :", data);
        T->rson = build_with_dfs(); // 递归建立右节点
    }
    return T;
}
int main()
{
    // 实验课测试
    bstree mine = build_with_dfs();
    kt key;
    printf("enter the ele to delete:");
    scanf("%d", &key.key);
    searchbst(mine, key);
}