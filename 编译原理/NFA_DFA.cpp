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
vector<node> orignfa;    // ��ʼnfa
set<int> tempset;        // ������հ�
set<char> zmb;           // �����ַ�����
set<int> srb;            // ״̬����
vector<set<int>> finans; // ����״̬
int chushi;
int zhongtai;
set<int> finzhongtai;      // ������̬
void closure(int numberid) // dfs��ͼ
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
void get_closure(int numberid) // ��ȡ��ȡe-closure�հ�
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
        for (int i = 0; i < finans.size(); i++) // �������״̬
        {
            cout << "now:{";
            for (auto &j : finans[i])
            {
                cout << j << " ";
            }
            cout << "}\n";
            for (auto &j : zmb) // ���ÿ���ַ�
            {
                set<int> nowtemp;         // move(a,i);
                for (auto &p : finans[i]) // ���ÿһ��״̬���е�ÿһ���ַ�ȥ��
                {
                    for (auto &u : orignfa) // �ҵ��Ƿ��ж�Ӧ�ı�
                    {
                        if (u.fromid == p && u.input == j)
                        {
                            nowtemp.insert(u.endid);
                        }
                    }
                }
                set<int> judans;
                bool flag = true;
                if (nowtemp.size() == 0) // �۳�һ���ռ�������
                {
                    flag = false;
                }
                else
                {
                    for (auto &x : nowtemp)
                    {
                        get_closure(x);
                        set_union(tempset.begin(), tempset.end(), judans.begin(), judans.end(), inserter(judans, judans.begin())); // �󽻼�
                    }
                    cout << "{";
                    for (auto &x : judans)
                    {
                        cout << x << " ";
                    }
                    cout << "}";
                    cout << endl;
                    for (int l = 0; l < finans.size(); l++) // ȫ��δ���ֵ�
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
                    // ����״̬����
                }
            }
        }
    }
};

int main()
{
    int temp;
    printf("\n�ߵĸ���:");
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
    printf("�����̬:");
    cin >> chushi;

    printf("������̬");
    cin >> zhongtai;
    get_closure(chushi);
    finans.push_back(tempset); // ��ʼ״̬
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