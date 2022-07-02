//归并排序（Merge_sorting）模板
//实例代码:所有的下标按照从1开始
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 31
int A[N], B[N];               // A为原始数据，B为辅助数据
void merge_sort(int l, int r) //升序的归并排序
{
    if (l == r) //判断是否到达递归边界，即递归到单一一个元素(左右端点值相等)
    {
        return;
    }
    int mid = (l + r) >> 1, k = l, i = l, j = mid + 1; //分区
    merge_sort(l, mid);
    merge_sort(mid + 1, r);    //递归排序
    while (i <= mid && j <= r) //循环赋值
    {
        if (A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) //当右区间全部赋值，左区间剩下
    {
        B[k++] = A[i++];
    }
    while (j <= r) //当左区间全部赋值，右区间剩下
    {
        B[k++] = A[j++];
    }
    for (int s = l; s <= r; s++) //更新原始数组
    {
        A[s] = B[s];
    }
}
int main()
{
    srand(time(0));
    for (int i = 1; i < N; i++)
    {
        A[i] = rand() % 31;
    }
    for (int i = 1; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    merge_sort(1, N - 1);
    for (int i = 1; i < N; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}