//赫夫曼树(最优二叉树)的相关理解
//基础知识点
/*
路径：从树中一个结点到另一个结点之间的分支构成这两个结点之间的路径
路径长度：路径上的分支数目
树的路径长度：从树根到每个结点的路径长度之和
结点的带权路径长度：从结点到树根之间的路径长度与结点上权的乘积
树的带权路径长度（WPL）：树中所有叶子结点的带权路径长度之和
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight; //权重
    int parent, lch, rch;
} HTNode, *HuffmanTree;
void select(HuffmanTree HT, int n, int &s1, int &s2) //找出森林中权值最小的两个
{
    int minum;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            minum = i;
            break;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (HT[i].weight < HT[minum].weight)
            {
                minum = i;
            }
        }
    }
    s1 = minum; //最小的
    for (i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && i != s1)
        {
            minum = i;
            break;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && i != s1)
        {
            if (HT[minum].weight < HT[minum].weight)
            {
                minum = i;
            }
        }
    }
    s2 = minum; //第二小的
}
void build_tree(HuffmanTree HT, int n)
{
    int m, i, s1, s2;
    if (n <= 1)
    {
        return;
    }
    m = 2 * n - 1;          // 数组共2n-1个元素
    HT = new HTNode[m + 1]; // 0号单元未用，HT[m]表示根节点
    for (i = 1; i <= m; i++)
    { // 将2n-1个元素的lch,rch,parent设置为0
        HT[i].lch = 0;
        HT[i].rch = 0;
        HT[i].parent = 0;
    }
    for (i = 1; i <= n; i++)
    { // 输入前n个元素的weight值
        scanf("%d", &HT[i].weight);
    }
    // 初始化结束，下面开始建立哈夫曼树
    for (i = n + 1; i <= m; i++)
    {
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lch = s1;
        HT[i].rch = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    printf("done!\n");
}
/*思路简述：
    有n个带权的节点，先将所有节点的左右儿子以及父节点初始化为0
    再建立一个2*n大小的森林数组
    先将已有带权值的树(目前实质是一个节点)放入森林
    从空位置开始遍历(即森林数组的第n+1位置开始),每次遍历当前位置之前的所有父节点为0的树，找到最小的两个节点，
    再将找到的节点化为当前遍历的树的左右儿子，并且将当前当前遍历树的权值更新为两个的和
    重复上述，直到遍历完n个节点(也就是两两合并之后，遍历之前再也找不到根节点为0的树了)

*/
int main()
{
    HuffmanTree ht;
    int n = 3;
    build_tree(ht, 3);
}
