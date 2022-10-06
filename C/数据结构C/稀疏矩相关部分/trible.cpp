//稀疏矩阵的三元组表示法
#include <stdio.h>
#include <stdlib.h>
typedef struct Trible //三元组
{
    int i;   //行标
    int j;   //列标
    int val; //数值
} * Te;
typedef struct martix
{
    Te num;          //动态开辟空间法(大小为非零值的大小)
    int len_raw;     //行的长度
    int len_col;     //列的长度
    int size_of_num; //非零元素大小
    int maxsize = 100;
    void build() //从一个二维数组建立一个矩阵并返回
    {
        size_of_num = 0;
        num = (Te)malloc(sizeof(struct Trible) * maxsize);
        int x, y;
        printf("enter your martix\n");
        printf("the len of row:");
        scanf("%d", &x);
        len_raw = x;
        printf("the len of col:");
        scanf("%d", &y);
        len_col = y;
        printf("enter your martix's ele:\n");
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                int val;
                scanf("%d", &val);
                if (val)
                {
                    (num + size_of_num)->i = i;
                    (num + size_of_num)->j = j;
                    (num + size_of_num)->val = val;
                    size_of_num++;
                }
            }
        }
    }
    void build_trible() //三元组方式创建稀疏矩阵
    {
        int x, y, t;
        printf("enter the len of raw:");
        scanf("%d", &x);
        printf("enter the len of col:");
        scanf("%d", &y);
        printf("enter the number of ele:");
        scanf("%d", &t);
        size_of_num = t;
        len_raw = x;
        len_col = y;
        num = (Te)malloc(sizeof(struct Trible) * t);
        for (int i = 0; i < t; i++)
        {
            int m, n, p;
            printf("enter %d_th ele's inf of martix:", i + 1);
            scanf("%d %d %d", &m, &n, &p);
            (num + i)->i = m - 1;
            (num + i)->j = n - 1;
            (num + i)->val = p;
        }
    }
    void show_trible() //三元组形式输出稀疏矩阵(不会按照行主序进行输出，完全按照输入的顺序输出)
    {
        for (int i = 0; i < size_of_num; i++)
        {
            printf("the %d_th row %d_th col: %d\n", (num + i)->i + 1, (num + i)->j + 1, (num + i)->val);
        }
    }
    void show_martix() //以矩阵形式输出稀疏矩阵
    {
        for (int i = 0; i < len_raw; i++)
        {
            for (int j = 0; j < len_col; j++)
            {
                int judge = 0;
                for (int z = 0; z < size_of_num; z++)
                {
                    if ((num + z)->i == i && (num + z)->j == j)
                    {
                        judge = (num + z)->val;
                    }
                }
                printf("%d ", judge);
            }
            printf("\n");
        }
    }
    martix Transpose() //矩阵的转置
    {
        martix b;
        b.len_col = len_raw;
        b.len_raw = len_col;
        b.size_of_num = size_of_num;
        b.num = (Te)malloc(sizeof(struct Trible) * size_of_num);
        for (int i = 0; i < size_of_num; i++)
        {
            (b.num + i)->i = (num + i)->j;
            (b.num + i)->j = (num + i)->i;
            (b.num + i)->val = (num + i)->val;
        }
        free(num);
        return b;
    }
} * x_martix;
int main()
{
    martix a;
    a.build();
    a.show_martix();
    printf("\n");
    a = a.Transpose();
    a.show_martix();
}