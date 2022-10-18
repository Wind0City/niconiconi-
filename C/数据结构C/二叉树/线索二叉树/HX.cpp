#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int ele;           //元素内容
    struct tree *lson; //左儿子
    struct tree *rson; //右儿子
    struct tree *par;  //后序线索化遍历时必须用到的父节点
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
    if (T->lson != NULL)
    {
        T->lson->par = T;
    }
    printf("the rson of %d :", data);
    T->rson = build(); //递归建立右节点
    if (T->rson != NULL)
    {
        T->rson->par = T;
    }
    return T;
}
void cluing(tr T) //递归线索化_后序
{
    if (T == NULL)
    {
        return;
    }
    cluing(T->lson);
    cluing(T->rson);
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
}
void Hx_BL(tr T) //后序线索化二叉树遍历
{
    tr S = T;
    tr just_now; //和pre一样的含义，这里单独拿出来讨论
    while (S->ltag == 0)
    {
        S = S->lson;
    } //先到最开始节点(左叶子节点)
    while (1)
    {
        if (S->rtag == 1) //遍历右儿子,按照后驱节点值输出
        {
            printf("%d ", S->ele);
            just_now = S;
            S = S->rson;
        }
        else
        {
            if (S->rson == just_now) //如果当前节点的右边儿子是上一个访问的
            {
                printf("%d ", S->ele); //输出
                if (T == S)            //当遍历到根节点的时候直接退出
                {
                    printf("done!\n");
                    return;
                }
                just_now = S; //更新
                S = S->par;   //更新为自身的父指针
            }
            else
            {
                S = S->rson; //不等于时更新为右儿子
                while (S->ltag == 0)
                {
                    S = S->lson;
                }
            }
        }
    }
} //画图理解

int main()
{ //测试代码
    printf("the root:");
    tr mine_tree = (tr)malloc(sizeof(struct tree));
    mine_tree = build();
    cluing(mine_tree);
    printf("done!\n");
    Hx_BL(mine_tree);
    printf("\n");
}