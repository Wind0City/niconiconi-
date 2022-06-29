//问题一
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void title(int n)//中间分割线
{
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout.fill('-');
        cout.width(4);
        cout << "-";
    }
    cout << endl;
}
int main()
{
    int n, m, i, j;
    cin >> n >> m; //维数及其输入

    int **p = new int *[n];
    for (i = 0; i <= n; i++)
    {
        p[i] = new int[m];
    }//二维空间动态开辟

    cout << "x|\t";
    for (i = 0; i <= m; i++)
    {
        cout << i << "\t";
    }//第一行内容

    title(m);

    for (i = 0; i <= n; i++)
    {
        cout << i << "|" << "\t";
        for (j = 0; j <= m; j++)
        {

            p[i][j] = i * j;
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }

    for ( i = 0; i <= n ; i++)
    {
        delete[]  p[i];
        p[i]=NULL;
    }
    delete[] p;
    p=NULL;//释放空间
}