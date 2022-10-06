//稀疏矩阵的十字链表表示法
#include <stdio.h>
#include <stdlib.h>
typedef struct Olnode //定义节点信息
{
    int row, col;
    int value;                   //和三元组一样的定义，列标以及值
    struct Olnode *right, *down; // right指向当前行的下一个信息节点,down为指向当前列的下一个信息节点
} * Oe;
typedef struct Cross_linked_list //十字链表表示方法
{
    Oe *row_head, *col_head;        //行头指针和列头指针
    int len_row, len_col, size_num; //行列以及非零元素个数
} * CLL;
void build(CLL QAQ) //十字链表法创建稀疏矩阵
{
    Oe last;
    int x, y, z; //行列数以及非零元素个数
    printf("enter the len_raw:\n");
    scanf("%d", &x);
    printf("enter the len_col:\n");
    scanf("%d", &y);
    printf("the num of eles\n");
    scanf("%d", &z);
    if (z <= 0 || z > x * y)
    {
        printf("error!\n");
        return;
    }
    QAQ->len_row = x;
    QAQ->len_col = y;
    QAQ->size_num = z;
    //为行列头指针开辟空间
    QAQ->row_head = (Oe *)malloc(sizeof(Oe) * (x + 1));
    QAQ->col_head = (Oe *)malloc(sizeof(Oe) * (y + 1)); //都多加一个让下标从1开始，方便操作
    if (!QAQ->row_head || !QAQ->col_head)
    {
        printf("error!\n");
        exit(1);
    }
    //下面两个循环赋值初始化必须有
    for (int i = 1; i <= x; i++)
    {
        *(QAQ->row_head + i) = NULL;
    }
    for (int i = 1; i <= y; i++)
    {
        *(QAQ->col_head + i) = NULL;
    }
    for (int i = 0; i < z; i++)
    {
        int m, n, p; //节点信息
        printf("the %d_th ele inf(r,c,v):\n", i + 1);
        scanf("%d %d %d", &m, &n, &p);
        last = (Oe)malloc(sizeof(struct Olnode)); //此处为创建一个新的信息节点
        last->row = m;
        last->col = n;
        last->value = p;
        last->right = NULL;
        last->down = NULL;
        if ((*(QAQ->row_head + m)) == NULL) //如果对应的头指针为空，直接赋值
        {

            *(QAQ->row_head + m) = last;
        }
        else //如果对应的头指针是有信息节点的
        {

            Oe temp = *(QAQ->row_head + m); //用来遍历的节点

            if (temp->col > n) //第一个就比当前的列值大
            {
                last->right = *(QAQ->row_head + m);
                *(QAQ->row_head + m) = last;
            }
            else
            {
                while (temp->right && temp->right->col < n) //判断顺序不能变化，得先判断存不存在
                {
                    temp = temp->right;
                }
                //循环拿出第一个不小于插入节点列值的节点的前一个结点
                last->right = temp->right;
                temp->right = last;
                //然后插进去
            }
        }
        /*  printf("row done\n"); */
        //下面对应列的插入也是一样的
        if ((*(QAQ->col_head + n)) == NULL)
        {
            *(QAQ->col_head + n) = last;
        }
        else
        {

            Oe temp = *(QAQ->col_head + n);
            if (temp->row > m)
            {
                last->down = *(QAQ->col_head + n);
                *(QAQ->col_head + n) = last;
            }
            else
            {

                while (temp->down && temp->down->row < m)

                {
                    temp = temp->down;
                }
                last->down = temp->down;
                temp->down = last;
            }
        }
        /*    printf("col done\n");
           printf("%d\t%d\t%d\n", (*(QAQ->row_head + m))->row, (*(QAQ->row_head + m))->col, (*(QAQ->row_head + m))->value);
           printf("done!\n"); */
    }
}
void show(CLL m) //三元组方式输出矩阵
{
    for (int i = 1; i <= m->len_row; i++)
    {
        if ((*(m->row_head + i)) != NULL)
        {
            Oe p = (*(m->row_head + i));
            while (p)
            {
                printf("%d %d %d\n", p->row, p->col, p->value);
                p = p->right;
            }
        }
    }
}
void show_martix(CLL m) //矩阵形式输出
{
    for (int i = 1; i <= m->len_row; i++)
    {
        for (int j = 1; j <= m->len_col; j++)
        {
            Oe p = *(m->row_head + i);
            int jude = 0;
            while (p)
            {
                if (p->row == i && p->col == j)
                {
                    jude = p->value;
                    break;
                }
                p = p->right;
            }
            printf("%d ", jude);
        }
        printf("\n");
    }
}
void insert(int m, int n, int p, CLL QAQ) //插入函数，辅助下面矩阵的转置，用来实现矩阵加法也可行，貌似可以用来build，所以build可能有点复杂了qaq
{
    if (!QAQ->row_head || !QAQ->col_head)
    {
        printf("error!\n");
        exit(1);
    }
    Oe last;
    last = (Oe)malloc(sizeof(struct Olnode));
    last->row = m;
    last->col = n;
    last->value = p;
    last->right = NULL;
    last->down = NULL;
    if ((*(QAQ->row_head + m)) == NULL) //如果对应的头指针为空，直接赋值
    {
        *(QAQ->row_head + m) = last;
    }
    else //如果对应的头指针是有信息节点的
    {

        Oe temp = *(QAQ->row_head + m); //用来遍历的节点
        if (temp->col > n)
        {
            last->right = *(QAQ->row_head + m);
            *(QAQ->row_head + m) = last;
        }
        else
        {
            while (temp->right && temp->right->col < n) //必须先判断temp的下一个是不是null！！！！
            {
                temp = temp->right;
            }
            last->right = temp->right;
            temp->right = last;
        }
    }
    /*  printf("row done\n"); */
    if ((*(QAQ->col_head + n)) == NULL)
    {
        *(QAQ->col_head + n) = last;
    }
    else
    {

        Oe temp = *(QAQ->col_head + n);
        if (temp->row > m)
        {
            last->down = *(QAQ->col_head + n);
            *(QAQ->col_head + n) = last;
        }
        else
        {
            while (temp->down && temp->down->row < m)

            {
                temp = temp->down;
            }
            last->down = temp->down;
            temp->down = last;
        }
    }
}
CLL Transpose(CLL m) //矩阵的转置
{
    CLL n = (CLL)malloc(sizeof(struct Cross_linked_list));
    n->len_col = m->len_row;
    n->len_row = m->len_col;
    n->size_num = m->size_num;
    n->row_head = (Oe *)malloc(sizeof(Oe) * (m->len_col + 1));
    n->col_head = (Oe *)malloc(sizeof(Oe) * (m->len_row + 1));
    /*  printf("m:\n");
     printf("%d %d %d\n", m->len_row, m->len_col, m->size_num);
     printf("n:\n");
     printf("%d %d %d\n", n->len_row, n->len_col, n->size_num); */
    for (int i = 1; i <= n->len_row; i++)
    {
        *(n->row_head + i) = NULL;
    }
    for (int i = 1; i <= n->len_col; i++)
    {
        *(n->col_head + i) = NULL;
    }
    //上面为正常先创建(注意逆置)
    for (int i = 1; i <= m->len_row; i++)
    {
        if ((*(m->row_head + i)) != NULL)
        {
            Oe p = (*(m->row_head + i));
            while (p)
            {
                insert(p->col, p->row, p->value, n); //将m中有元素的挨个插入(注意行列倒置)
                p = p->right;
            }
        }
    }
    return n;
}
int main()
{
    //测试代码
    CLL mysz = (CLL)malloc(sizeof(struct Cross_linked_list));
    build(mysz);
    printf("\ntrible:\n");
    show(mysz);
    printf("\nmartix\n");
    show_martix(mysz);
    CLL new_mysz = Transpose(mysz);
    show_martix(new_mysz);
}
/*参考：https://blog.csdn.net/qq_50710984/article/details/114100664?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166497144016782391834792%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=166497144016782391834792&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-8-114100664-null-null.142^v51^control,201^v3^control_1&utm_term=%E5%8D%81%E5%AD%97%E9%93%BE%E8%A1%A8%E6%B3%95&spm=1018.2226.3001.4187*/
/*https://blog.csdn.net/m0_62909149/article/details/124071262?ops_request_misc=&request_id=&biz_id=102&utm_term=%E5%8D%81%E5%AD%97%E9%93%BE%E8%A1%A8%E6%B3%95&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-124071262.nonecase&spm=1018.2226.3001.4187*/