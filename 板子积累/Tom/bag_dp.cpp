//背包dp
/*
第一类:部分背包dp，用贪心的解决思路
特点 物品可按单位价值任意分割
*/

#include <bits/stdc++.h>
using namespace std;
int m, n;
int w[100]; //重量
int v[100]; //价值
int dp[100][100];
int bag01() // 01背包问题
{
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }                            //初始化
    for (int i = 1; i <= n; i++) //从二维数组的角度来看，是从右上角开始
    {
        for (int j = m; j >= 0; j--)
        {
            if (j < w[i]) //如果此时的剩余重量小于物重
            {
                dp[i][j] = dp[i - 1][j]; //不取，即价值保持不变
            }
            else //可以取，重量够
            {
                //能取的情况下也是要看取和不取哪个的价值更大
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                //取的情况下dp[i - 1][j - w[i]]表示空出当前物体重量空间后的价值，再加上取这个后的价值就是在这个节点取这个物品的价值
            }
        }
    }
    return dp[m][n];
}
int bag01_plus()
{
    int dp2[500];
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp2[j] = max(dp2[j], dp2[j - w[i]] + v[i]);
        }
        /* 改成下面这种便是完全背包问题
        for (int j = w[i]; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }*/
    }
    printf("%d", dp[m]);
}
