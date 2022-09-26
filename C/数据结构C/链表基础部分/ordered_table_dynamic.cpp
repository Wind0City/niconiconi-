//顺序表的动态开辟法表示
//主要是对插入，删除操作的写
//查找，直接以指针形式取下标即可
//查看长度，直接用一个值来记录即可，即下面结构体中的lenth
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int *ele;    //指向动态数组的第一个指针
    int lenth;   //代表数组的大小
    void print() //输出函数
    {
        for (int i = 0; i < lenth; i++)
        {
            printf("%d ", *(ele + i));
        }
        printf("\n");
    }
} a;
void insert() //插入操作
{
    int x, e;
    printf("the x_th you want to insert:");
    scanf("%d", &x);
    x--; //因为下标是从0开始的
    if (x >= a.lenth || x < 0)
    {
        printf("error!");
        exit(1);
        return;
    }
    printf("the ele you want to insert:");
    scanf("%d", &e);
    a.ele = (int *)realloc(a.ele, sizeof(int) * (a.lenth + 1)); //重新分配空间操作
    a.lenth++;                                                  //长度也要增加
    for (int i = a.lenth - 1; i > x; i--)                       //先将x位置上的元素全部后移
    {
        *(a.ele + i) = *(a.ele + i - 1);
    }
    *(a.ele + x) = e;
    a.print();
}
void delete_ele()
{
    int x;
    printf("the x_th you want to delete:");
    scanf("%d", &x);
    x--; //因为下标是从0开始的
    if (x >= a.lenth || x < 0)
    {
        printf("error!");
        exit(1);
        return;
    }
    for (int i = x; i < a.lenth - 1; i++)//先从要删的位置下一位开始将元素向前移
    {
        *(a.ele + i) = *(a.ele + i + 1);
    }
    a.lenth--;//长度减小
    a.ele = (int *)realloc(a.ele, sizeof(int) * a.lenth);//严谨情况下重新分配
    a.print();
}
int main()
{
    int n;
    printf("enter the length of array:");
    scanf("%d", &n);
    a.lenth = n;
    a.ele = (int *)malloc(sizeof(int) * n); //动态开辟空间
    for (int i = 1; i <= n; i++)
    {
        *(a.ele + i - 1) = i; //简单赋值即可
    }
    a.print();
    printf("%d\n", a.lenth);
    insert();
    printf("%d\n", a.lenth);
    delete_ele();
    printf("%d\n", a.lenth);
}
