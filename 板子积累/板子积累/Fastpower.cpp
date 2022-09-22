/*快速幂与矩阵快速幂*/
/*矩阵快速幂的实现其实就是定义好矩阵的乘法之后再正常的进行快速幂*/
//取模运算法则：
/*
(a + b) % p = (a % p + b % p) % p （1）

(a - b) % p = (a % p - b % p ) % p （2）

(a * b) % p = (a % p * b % p) % p （3）**重点
*/
/*
计算时间：
clock_t start, finish;
 start = clock();程序开始前
 finish=clovk()；程序结束后
 double(start-finish)为时间
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000;
ll n; //阶数
struct node
{
    ll m[100][100];

} ans, res; //定义矩阵类型的结构体,ans为答案矩阵，res为初始矩阵
node mul(node A, node B)
{
    int i, j, k;
    node temp;              //定义一个临时矩阵，存放A*B的结果
    for (i = 0; i < n; i++) //先全部定义为0
    {
        for (j = 0; j < n; j++)
        {
            temp.m[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) //矩阵相乘的代码
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                temp.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return temp;
}
void quickpower(int M, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                ans.m[i][j] = 1;
            }
            else
                ans.m[i][j] = 0;
        }
    } //这里是思想的转换，之前我们定义为1去计算，所以我们先初始化ans为
    //单位矩阵，我们知道单位矩阵与任何矩阵的乘积为其本身
    while (M) //快速幂的步骤
    {
        if (M & 1)
        {
            ans = mul(ans, res);
        }
        res = mul(res, res);
        M = M >> 1;
    }
}
ll fastpower(ll base, ll power) //核心思想体现
{
    ll ans = 1;
    while (power > 0)
    {
        if (power & 1) //等价于power%2==1
        {
            ans = ans * base % MOD;
        }
        power >>= 1; //等价于power=power/2;
        base = (base * base) % MOD;
    }
    return ans;
}