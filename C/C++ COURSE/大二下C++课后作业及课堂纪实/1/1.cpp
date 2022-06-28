#include <iostream> //
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define N 20
using namespace std;
void comfort()
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
}
void swap1(int a, int b) //正常函数参数单向传递
{
    int temp = a;
    a = b;
    b = temp;
}
void swap2(int &a, int &b) //“引用方法”可在函数内部成功调换
{
    int temp = a;
    a = b;
    b = temp;
}
int FindMax(int *p, int length, int &ref) //用引用代替原来的指针
{
    int i, pos = 0;
    ref = p[0]; //当作一个值用
    for (i = 0; i < length; i++)
    {
        if (ref < *(p + i))
        {
            ref = *(p + i);
            pos = i;
        }
    }
    return pos;
}
int main()
{

    int x = 5, y = 6;
    cout << x << " " << y << endl;
    swap1(x, y);
    cout << "in swap1 " << x << "," << y << endl;
    swap2(x, y);
    cout << "in swap2 " << x << "," << y << endl;

    comfort();

    srand((unsigned int)time(NULL));
    // int *p=(int*)malloc(sizeof(int)*N);C的动态开辟空间
    // int *p = new int(5);
    int *p = new int[N]; // C++的动态开辟空间
    for (int i = 0; i < N; i++)
    {
        *(p + i) = rand() % 50 + 1;
        cout << setw(4) << *(p + i);
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    //引用：
    // int a = 5;
    // int &ref = a; //"ref"is another name of "a"

    int mymax;
    int ans = FindMax(p, N, mymax); //等价于 int &ref=max
    //引用效率高于指针
    cout << "max is" << mymax << " "
         << "poisition is" << ans << endl;
    // free(p);C的动态开辟空间之后释放方法
    delete[] p; // C++的动态开辟空间释放方法
    return 0;
}