#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int cnt = 0;          //计数
int tree[maxn][30];   //树图,与链式前向星的思路比较,这个只是用来记录连接情况的
int num[maxn];        //在查找具体但此时表示字典树是否有以这个为结尾的
void insert(string s) //插入操作
{
    int u = 0; //从根节点出发
    for (int i = 0; i < s.size(); i++)
    {
        int now = s[i] - 'a'; //转化为整型数值比较好操作
        if (!tree[u][now])    //如果这一阶段的这个字母还没有用过得先用
        {
            tree[u][now] = ++cnt; //开辟操作
        }
        u = tree[u][now]; //指向s的下一个字母重复上述过程
    }
    num[u]++;
}
int find(string s) //查找操作
{
    int u = 0; //还是从根节点出发
    for (int i = 0; i < s.size(); i++)
    {
        int now = s[i] - 'a';
        if (!tree[u][now]) //如果走到这一步没有匹配的字母
        {
            return 0; //直接返回
        }
        u = tree[u][now]; //指向下一层
    }
    return num[u]; //返回最终的出现的次数
}
void init()
{
    memset(tree, 0, sizeof(tree));
    memset(num, 0, sizeof(num));
}
int main()
{
    init();
    insert("aa");
    insert("a");
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        printf("%d\n", find(s));
    }
    return 0;
}