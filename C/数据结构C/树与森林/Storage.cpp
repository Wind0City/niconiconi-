//树的三种存储结构总结
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define maxn 10005
using namespace std;
//首先是双亲表示法
typedef struct node //表示一个节点
{
    int data;   //该节点存储的信息
    int parent; //该节点的父节点
} ne;
typedef struct tree_parents //表示一棵树
{
    ne nodes[maxn]; //这棵树的所有节点信息
    int n;          //树的大小
} trep;
trep minr_tree;
void build_parents()
{
    int n;
    printf("the number of your tree: ");
    scanf("%d", &n);
    minr_tree.n = n;
    if (n <= 0 || n >= maxn)
    {
        printf("error!\n");
        exit(1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("the node number/the parent/the inf:\t");
        int s;
        scanf("%d", &s);                         //节点编号
        scanf("%d", &minr_tree.nodes[s].parent); //节点的父亲节点
        scanf("%d", &minr_tree.nodes[s].data);   //节点的信息
    }
}
//孩子表示法
typedef struct CTNode //孩子结点
{
    int child;           //孩子结点在数组中的位置
    struct CTNode *next; //下一个孩子
} CTNode;

typedef struct //顺序存储表
{
    int data;
    struct CTNode *firstChild; //第一个孩子
} CTBox;

typedef struct
{
    CTBox nodes[maxn];
    int n, r; //结点数和根的位置
} CTree;
CTree child_tree;
void build_child() //孩子表示法的建树
{
    //先创建所有节点
    printf("the number of node:");
    scanf("%d", &child_tree.n);
    for (int i = 1; i <= child_tree.n; i++)
    {
        printf("the inf of node %d:", i);
        scanf("%d", &child_tree.nodes[i].data);
        child_tree.nodes[i].firstChild = NULL;
    }
    //循环建立所有节点的子节点
    for (int i = 1; i < child_tree.n; i++)
    {
        printf("build the children of node %d\nthe number:", i);
        int num;
        scanf("%d", &num);
        CTNode *p;
        CTNode *last;
        last = child_tree.nodes[i].firstChild;
        for (int j = 1; j <= num; j++) //根据给的儿子节点数目循环
        {
            printf("the %d_th child:", j);
            int l;
            scanf("%d", &l);
            if (l <= 0 || l > child_tree.n || l == i) //判断不合法
            {
                printf("the node not exist,next one\n");
                continue;
            }
            else //此处用尾插法建立子节点单链表
            {
                p = (CTNode *)malloc(sizeof(CTNode));
                p->child = l;
                p->next = last;
                last = p;
                child_tree.nodes[i].firstChild = p;
            } //这样建立之后，每个节点的第一个儿子指针指向的时最后一个儿子节点
        }
    }
}
//孩子兄弟表示法
typedef struct CSNode
{
    int data;                                //数据
    struct CSNode *firstchild, *nextsibling; //第一个孩子节点,第一个兄弟节点
} * ce;
ce build_cs() //孩子兄弟表示法的建树,输入数据为-1表示无节点
{
    queue<ce> de;                                //需要辅助队列,层次建树
    ce help;                                     //辅助指针
    ce root = (ce)malloc(sizeof(struct CSNode)); //首先建立根节点
    printf("enter the root of the tree:");
    int data;
    scanf("%d", &data);
    root->data = data;
    root->firstchild = NULL;
    root->nextsibling = NULL;
    de.push(root); //根节点的相关初始化
    while (!de.empty())
    {
        ce now = de.front(); //拿出队首
        de.pop();
        printf("the firstchild of %d: ", now->data);
        scanf("%d", &data);
        if (data != -1) //第一个儿子节点
        {
            help = (ce)malloc(sizeof(struct CSNode));
            help->data = data;
            help->firstchild = NULL;
            help->nextsibling = NULL;
            now->firstchild = help;
            de.push(help);
            printf("the firstchild done!\n");
        }
        else
        {
            continue;
        }
        printf("the brother of the firstchild:\n");
        while (1) //之后的节点全部时第一个儿子结点的兄弟节点
        {
            printf("the node : ");
            scanf("%d", &data);
            if (data == -1)
            {
                break;
            }
            help = (ce)malloc(sizeof(struct CSNode)); //此处仍是头插法
            help->data = data;
            help->firstchild = NULL;
            help->nextsibling = NULL;
            help->nextsibling = now->firstchild->nextsibling;
            now->firstchild->nextsibling = help;
            de.push(help);
            printf("brother done!\n");
        }
    }
    return root;
}
void show(ce root) //先序遍历孩子兄弟表示法的树
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        show(root->firstchild);
        show(root->nextsibling); //调换顺序即可实现中序以及后序遍历
    }
}
/*其他两种树结构的遍历方法自行推导*/
int main()
{
    /*三种树结构的建树方法测试代码*/
    ce mine_cstree = build_cs();
    show(mine_cstree);
    build_parents();
    build_child();
}
//参考文献：https://blog.csdn.net/weixin_43899645/article/details/107908178?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166661717116782425163916%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166661717116782425163916&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-107908178-null-null.142^v59^pc_search_tree,201^v3^control_1&utm_term=%E6%A3%AE%E6%9E%97&spm=1018.2226.3001.4187