//模板
#include <iostream>
using namespace std;
template <class T> //一般多个虚拟参数
void bubbleSort(T *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubbleSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}