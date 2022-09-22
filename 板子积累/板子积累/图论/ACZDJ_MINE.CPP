#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int trie[maxn][30];
int fail[maxn];
int cntword[maxn];
int cnt = 0;
void insert(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int now = s[i] - 'a';
        if (!trie[u][now])
        {
            trie[u][now] = ++cnt;
        }
        u = trie[u][now];
    }
    cntword[u]++;
}
void getfail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (trie[0][i])
        {
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (trie[now][i]) //可以理解为这个值就是这个串以i结尾的节点位置
            {
                fail[trie[now][i]] = trie[fail[now]][i]; //翻译：如果下个节点存在，则当前节点的fail指针指向父节点指向的fail指针的同字符节点
                q.push(trie[now][i]);                    //入队
                //举例：this。到i了，is是存在的，fail指针就会指向同后缀的is节点，fail指针bfs构建保证肯定是有值的，要么为0(不存在啊),要么指向存在的节点
                //（数组模拟空间的优势所在
            }
            else
            {
                trie[now][i] = trie[fail[now]][i]; //举例：this，到s末尾了，如果文本串是thise，则他的fail指针指向trie[s][e]这个节点去
            }
        }
    }
}
int query(string s)
{
    int now = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {                                //遍历文本串
        now = trie[now][s[i] - 'a']; //从s[i]点开始寻找
        for (int j = now; j && cntword[j] != -1; j = fail[j])
        {
            //一直向下寻找,直到匹配失败(失败指针指向根或者当前节点已找过).
            ans += cntword[j];
            cntword[j] = -1; //将遍历国后的节点标记,防止重复计算
        }
    }
    return ans;
}
int main()
{
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }
    fail[0] = 0;
    getfail();
    /*     for (int i = 0; i < cnt; i++)
        {
            printf("fail[%d]:%d\n", i, fail[i]);
        } */

    cin >> s;
    cout << query(s) << endl;
    cin >> s;
    cout << query(s) << endl;
    return 0;
}