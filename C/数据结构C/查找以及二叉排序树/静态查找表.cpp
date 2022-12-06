// 以单个int为关键字域以及实型的静态查找表示例
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int key;
} node;

typedef struct
{
    node *elem; // 元素,注意的是第一个是置空的
    int length; // 元素的个数
} SSTable;
SSTable create() // 创建表，正常动态开辟并返回
{
    SSTable new_table;
    int l;
    printf("the length:");
    scanf("%d", &l);
    new_table.length = l;
    new_table.elem = (node *)malloc(sizeof(node) * (l + 1));
    printf("the elems:");
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &new_table.elem[i].key);
    }
    printf("create success!\n");
    return new_table;
}
int search_seq(SSTable st, int key) // 顺序查找
{
    st.elem[0].key = key; // 都一个位置作为监视哨，当下标越界(到头时)省略检查，直接返回
    int i;
    for (i = st.length; st.elem[i].key != key; --i)
        ;     // 因为监视哨的存在，从后往前找
    return i; // 监视哨的作用就在这体现，直接返回即可
}
int search_bin(SSTable st, int key) // 折半查找(二分查找),前提要排好序
{
    int low = 1;
    int high = st.length; // 定义初始上下界
    int mid;
    while (low <= high) // 二分的套路
    {
        mid = (low + high) >> 1;
        if (key == st.elem[mid].key)
        {
            return mid;
        }
        else if (key < st.elem[mid].key) // 区间向左
        {
            high = mid - 1;
        }
        else // 区间向右
        {
            low = mid + 1;
        }
    }
    return 0; // 实在没查到
}
int search_bin_digui(SSTable &st, int key, int low, int high) // 二分查找的递归写法,初始边界为1-length
{
    // 比较简单，不做赘述
    int mid = (low + high) >> 1;
    if (st.elem[mid].key == key)
    {
        return mid;
    }
    else if (st.elem[mid].key < key)
    {
        return search_bin_digui(st, key, mid + 1, high);
    }
    else
    {
        return search_bin_digui(st, key, low, mid - 1);
    }
    return 0;
}
int main()
{
    SSTable mine = create();
    // 系列操作
}