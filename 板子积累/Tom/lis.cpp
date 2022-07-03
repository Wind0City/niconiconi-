//动态规划解决最长上升子序列LIS O(n*n)
//有长度为 n 的序列 S，求其 LIS 长度。
#include <iostream>
#include <algorithm>
using namespace std;
//一维dp数组解决
int dp[100];
int n;
void LIS(int s[])
{
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (s[i] > s[j])
            {
                dp[i] = max(dp[i], dp[j] + 1); //逐步更新的
            }
        }
    }
    //最后返回的是dp数组中的最大值，dp[i]代表的是以第i个元素为结尾的lis长度
}

//贪心加二分思想优化版O(nlogn)
//此时dp[i]代表的是长度为i的lis结尾元素
void LIS_PLUS(int s[])
{
    int len;
    len = 1;
    dp[len] = s[1]; //初始化
    for (int i = 2; i <= n; i++)
    {
        if (s[i] > dp[len]) //如果此时遍历的点比当前维护的lis结尾元素大，直接站上去
        {
            dp[len++] = s[i];
        }
        else //相反的,如果此时遍历的点比当前维护的lis结尾元素小，说明在维护的dp中结尾元素有过大的，贪心贪的就是这个
        {
            //查找维护的dp中可以用s[i]替换的元素位置，元素位置便是更新之后的lis长度
            int pos = lower_bound(dp + 1, dp + len + 1, s[i]) - dp;
            //而此时的lis结尾元素便是s[i]
            dp[pos] = s[i];
        }
    }
}
