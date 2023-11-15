#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3;
struct node
{
    int fromid;
    char input;
    int endid;
    node(int id, char ch, int to) : fromid(id), input(ch), endid(to){};
};
int jud[maxn];
vector<node> orignfa;    // 初始nfa
set<int> tempset;        // 辅助求闭包
set<char> zmb;           // 输入字符数组
set<int> srb;            // 状态集合
vector<set<int>> finans; // 最终状态
int chushi;
int zhongtai;
set<int> finzhongtai;      // 最终终态
void closure(int numberid) // dfs跑图
{
    jud[numberid] = 1;
    for (auto &i : orignfa)
    {
        if (i.fromid == numberid && i.input == '#' && jud[i.endid] == 0)
        {
            tempset.insert(i.endid);
            //  cout << "insert " << i.endid << endl;
            closure(i.endid);
        }
    }
}
void get_closure(int numberid) // 获取获取e-closure闭包
{
    set<int>().swap(tempset);
    memset(jud, 0, sizeof(jud));
    tempset.insert(numberid);
    // cout << "insert " << numberid << endl;
    closure(numberid);
}
class MyDFA
{
private:
    vector<node> minedfa;

public:
    MyDFA() {}
    void show_dfa()
    {
        for (auto &i : minedfa)
        {
            cout << i.fromid << "--[" << i.input << "]-->" << i.endid << endl;
        }
        cout << "end:";
        for (auto &p : finzhongtai)
        {
            cout << p << " ";
        }
        cout << endl;
    }
    void nfa_dfa()
    {
        for (int i = 0; i < finans.size(); i++) // 遍历左侧状态
        {
            cout << "now:{";
            for (auto &j : finans[i])
            {
                cout << j << " ";
            }
            cout << "}\n";
            for (auto &j : zmb) // 针对每个字符
            {
                set<int> nowtemp;         // move(a,i);
                for (auto &p : finans[i]) // 左侧每一个状态集中的每一个字符去跑
                {
                    for (auto &u : orignfa) // 找到是否有对应的边
                    {
                        if (u.fromid == p && u.input == j)
                        {
                            nowtemp.insert(u.endid);
                        }
                    }
                }
                set<int> judans;
                bool flag = true;
                if (nowtemp.size() == 0) // 聚成一个空集不加入
                {
                    flag = false;
                }
                else
                {
                    for (auto &x : nowtemp)
                    {
                        get_closure(x);
                        set_union(tempset.begin(), tempset.end(), judans.begin(), judans.end(), inserter(judans, judans.begin())); // 求交集
                    }
                    cout << "{";
                    for (auto &x : judans)
                    {
                        cout << x << " ";
                    }
                    cout << "}";
                    cout << endl;
                    for (int l = 0; l < finans.size(); l++) // 全新未出现的
                    {
                        if (finans[l] == judans)
                        {
                            minedfa.push_back(node(i + 1, j, l + 1));
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    minedfa.push_back(node(i + 1, j, (int)finans.size() + 1));
                    if (judans.count(zhongtai) != 0)
                    {
                        finzhongtai.insert((int)finans.size() + 1);
                    }
                    finans.push_back(judans);
                    // 加入状态集合
                }
            }
        }
    }
};

int main()
{
    int temp;
    printf("\n边的个数:");
    cin >> temp;
    for (int i = 1; i <= temp; i++)
    {
        int f, t;
        char c;
        cin >> f >> c >> t;
        orignfa.push_back(node(f, c, t));
        if (c != '#')
            zmb.insert(c);
    }
    printf("输入初态:");
    cin >> chushi;

    printf("输入终态");
    cin >> zhongtai;
    get_closure(chushi);
    finans.push_back(tempset); // 初始状态
    MyDFA O_o;
    O_o.nfa_dfa();
    /*  for (int i = 0; i < finans.size(); i++)
     {
         cout << "{";
         for (auto &p : finans[i])
         {
             cout << p << " ";
         }
         cout << "}";
         cout << endl;
     } */
    O_o.show_dfa();
    return 0;
}