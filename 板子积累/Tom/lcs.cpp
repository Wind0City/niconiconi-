//动态规划解决LCS（最长公共子序列）
//问题模板:长度为n和m的两个字符串
#include <iostream>
#include <string>
using namespace std;
int find(string x, string y)
{
    int n = x.length();
    int m = y.length();
    int dp[100][100];
    //更新边界情况
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    //正常的dp数组更新
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // dp数字完成后
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
}
int main()
{
    string s1("whtasd");
    string s2("htad");
    cout << find(s1, s2);
}