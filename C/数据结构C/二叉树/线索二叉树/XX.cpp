#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int ele;           //元素内容
    struct tree *lson; //左儿子
    struct tree *rson; //右儿子
    int ltag;          //左标记
    int rtag;          //右标记
} * tr;
tr pre = NULL; //当前遍历节点的上一个遍历节点,注意初始赋值
tr build()
{

    tr T; //先建立一个节点
    int data;
    scanf("%d", &data); //输入数据
    if (data == -1)     //-1时建树失败
    {
        return NULL;
    }
    T = (tr)malloc(sizeof(struct tree)); //分配内存空间
    T->ele = data;
    printf("the lson of %d :", data);
    T->lson = build(); //递归建立左节点
    printf("the rson of %d :", data);
    T->rson = build(); //递归建立右节点
    return T;
}
void cluing(tr T) //递归线索化_先序
{
    if (T == NULL)
    {
        return;
    }
    if (!T->lson) //左儿子不存在的情况
    {
        T->ltag = 1;   //标记打上
        T->lson = pre; //将前驱节点指向pre（或者理解成将pre的下一个指向当前
    }
    else
    {
        T->ltag = 0; //正常情况不需要标记
    }
    if (pre)
    {
        if (!pre->rson) // pre的右儿子不存在
        {
            pre->rtag = 1; //标记
            pre->rson = T; // pre的下一个指向当前
        }
        else
        {
            pre->rtag = 0;
        }
    }
    pre = T;
    //先处理再递归处理左右
    if (T->ltag == 0)
    {
        cluing(T->lson);
    }
    if (T->rtag == 0)
    {
        cluing(T->rson);
    }
}
void xx_BL(tr S) //先序线索化二叉树遍历
{
    tr T = S;
    while (T != NULL)
    {
        while (T->ltag == 0) //按照先序输出的规律，不断输出左子节点
        {
            printf("%d ", T->ele);
            T = T->lson;
        }
        printf("%d ", T->ele); //遇到左叶子节点停止，
        T = T->rson;           //这里可能是后驱节点，也有可能是右儿子
    }
    printf("done!\n");
}

int main()
{
    printf("the root:");
    tr mine_tree = (tr)malloc(sizeof(struct tree));
    mine_tree = build();
    cluing(mine_tree);
    printf("done!\n");
    xx_BL(mine_tree);
    printf("\n");
}