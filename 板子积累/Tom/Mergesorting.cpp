//时间复杂度的计算，只关注时间复杂度式子增长速度最大的一个
//选择排序，插入排序复杂度O（n*n）
//归并排序：递归方法,建议画图
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[20];
    int n = 20;
    int l = 1, r = n;
    int b[114514];
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1, k = 1;
    while (i <= mid && j <= r) //比较
    {
        if (a[i] <= b[j])
        {
            b[k] = a[i];
            k++, i++;
        }
        else //这也可以算一下逆序数
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) //右边的数组合并完了，左边剩下
        b[k++] = a[i++];
    while (j <= r) //同上，右边剩下的
        b[k++] = a[j++];
    for (int i = l; i <= r; i++) // a是排序的，重新将辅助数组c赋值给a
    {
        a[i] = b[i];
    }
}