//简单的字符串哈希模板
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL; //无符号长整型体是会自动取模的
const int base = 13331;         //转化的进制数，尽量是131 1331 13331....，（这样的进制的哈希碰撞概率会低一点
#define maxn 10005
ULL h[maxn], x[maxn]; //为了字符串匹配，可以结合前缀和预处理的思想，把字符串区间的方式通过对应的进制表示,x是每一位对应的进制
int n;
void bkdr_hash(string s) //初始化操作
{
    h[0] = s[0];
    x[0] = 1;
    for (int i = 1; i < s.size(); i++)
    {
        h[i] = h[i - 1] * base + s[i]; //类似于数字字符串转化为数字的操作
        x[i] = x[i - 1] * base;        //对应的进制位数也要更新
    }
}
ULL get_hash(int left, int right) //得到区间的hash值
{
    if (!left) //左节点为0直接返回对应的hash【right】
    {
        return h[right];
    }
    return h[right] - h[left - 1] * x[right - left + 1];
}
int main()
{
    string s;
    cin >> s;
    bkdr_hash(s);
    for (int i = 0; i < s.size() - 1; i++)
    {
        cout << get_hash(i, i + 1) << " ";
    }
    cout << endl;
}