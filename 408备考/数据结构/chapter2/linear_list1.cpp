/*线性表-顺序表及其各种功能的实现*/
/*重点介绍动态实现*/
#include <stdio.h>
#include <stdlib.h>

#define max_size 10 // 定义最大长度

/*=========================定义============================*/
struct static_list // 静态实现(就是数组)
{
    int data[max_size];
    int len;
};

struct dynamic_list // 动态实现
{
    int *data;
    int len;      // 当前长度
    int listsize; // 分配的存储容量
};

/*=========================初始化&销毁==========================*/
bool init_dynamic_list(dynamic_list &L) // 初始化
{
    L.data = (int *)malloc(max_size * sizeof(int)); // malloc
    if (L.data == NULL)                             // 分配失败
    {
        return false;
    }
    L.len = 0;             // 当前长度
    L.listsize = max_size; // 最大长度
    return true;
}
bool delte_dynamic_list(dynamic_list &L) // 销毁
{
    free(L.data);
    L.len = 0;
    return true;
}

/*=========================操作实现==========================*/
bool insert(dynamic_list &L, int i, int x) // 插入操作，在第i个位置上插入x
{
    if (L.len == L.listsize) // 个数到达上线
    {
        return false;
    }
    int temp, now;            // 中间介质，辅助交换
    temp = *(L.data + i - 1); // 真实位置，从0开始
    *(L.data + i - 1) = x;
    for (int j = i; j <= L.len; j++)
    {
        now = *(L.data + j);  // 记录当前值
        *(L.data + j) = temp; // 将前驱元素值赋给当前值
        temp = now;           // 记录当前值
    }
    L.len++; // 长度变换
    return true;
}
bool erase(dynamic_list &L, int i) // 删除操作，删除第i个位置的元素
{
    if (i - 1 > L.len) // 位置不合理
    {
        return false;
    }
    for (int j = i; j < L.len; j++)
    {
        *(L.data + j - 1) = *(L.data + j);
    }
    L.len--;
    return true;
}
int find_pos(dynamic_list &L, int i) // 按位置查找
{
    if (i - 1 > L.len) // 位置不合法
    {
        return -1;
    }
    int ans = *(L.data + i - 1);
    return ans;
}
int find_val(dynamic_list &L, int x) // 按值查找
{
    int pos = -1;
    for (int i = 0; i < L.len; i++)
    {
        if (*(L.data + i) == x)
        {
            pos = i;
        }
    }
    return pos + 1; // 返回值相等的最后一个位置
}
void show(dynamic_list &L) // 输出顺序表信息
{
    printf("len:%d\nlist_size:%d\n", L.len, L.listsize);
    printf("elements: ");
    for (int i = 0; i < L.len; i++)
    {
        printf("%d ", *(L.data + i));
    }
    printf("\n==============================\n");
}

/*===============================================================*/

int main()
{
    dynamic_list L;
    init_dynamic_list(L);
    show(L);
    printf("插入操作示范:\n");
    insert(L, 1, 1);
    show(L);
    insert(L, 1, 2);
    show(L);
    insert(L, 1, 3);
    show(L);
    insert(L, 1, 4);
    show(L);
    printf("查找操作示范:\n");
    printf("查找第三位上的数:%d\n", find_pos(L, 3));
    printf("查找值为2的位置:%d\n", find_val(L, 2));
    show(L);
    printf("删除操作示范:\n");
    erase(L, 1);
    show(L);
    erase(L, 1);
    show(L);
    erase(L, 1);
    show(L);
    erase(L, 1);
    show(L);

    return 0;
}