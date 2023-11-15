#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define endl '\n'
struct node // һ����λ��
{
    int fromid; // ��ʼ��
    char input; // Ȩֵ,���ϵ��ַ�
    int endid;  // ��ֹ��
    // ����
    node(int id, char input, int nextid) : fromid(id), input(input), endid(nextid) {}
};
bool cmp(node &a, node &b)
{

    if (a.fromid == b.fromid)
    {
        if (a.endid == b.endid)
        {
            return a.input == '-' ? 0 : 1;
        }
        return a.endid < b.endid;
    }
    return a.fromid < b.fromid;
}
class MyNFA
{
private:
    string oristr;        // ��ʼ����ʽ
    vector<node> minedfa; // ���մ洢�����б�

public:
    static int Staid; // ״̬��
    MyNFA(string str) : oristr(str) {}
    void shownfa();
    void str_nfa(); // ���Ĵ�
};
int MyNFA::Staid = 0;
int main()
{
    string str = "ab*(a*|(ab)*)";
    MyNFA O_o(str);
    O_o.str_nfa();
    O_o.shownfa();
    return 0;
}
void MyNFA::str_nfa()
{
    stack<int> staids; // �洢��ʼ���к�
    stack<int> endids; // �洢��ֹ���к�
    stack<char> strs;  // �ַ���
    staids.push(Staid++);
    endids.push(Staid++);
    strs.push('$');
    for (auto &i : oristr)
    {
        int ed;
        int st;
        int nextid;
        int preid;
        int topnum;
        char ch = i;
        cout << i;
        switch (ch)
        {
        case '(':
            endids.push(Staid++);
            strs.push('(');
            break;
        case ')':
            ed = endids.top();
            st = staids.top();
            minedfa.push_back(node(st, '-', ed));
            ch = strs.top();
            while (ch != '(')
            {
                nextid = staids.top();
                staids.pop();
                preid = staids.top();
                if (ch != '#')
                {
                    minedfa.push_back(node(preid, ch, nextid));
                }
                strs.pop();
                ch = strs.top();
            }
            strs.pop();
            strs.push('#');
            topnum = endids.top();
            staids.push(topnum);
            endids.pop();
            break;
        case '|':
            ed = endids.top();
            st = staids.top();
            minedfa.push_back(node(st, '-', ed));
            ch = strs.top();
            while (ch != '(' && ch != '$')
            {
                nextid = staids.top();
                staids.pop();
                preid = staids.top();
                if (ch != '#')
                {
                    minedfa.push_back(node(preid, ch, nextid));
                }
                strs.pop();
                ch = strs.top();
            }
            break;
        case '*':
            nextid = staids.top();
            staids.pop();
            preid = staids.top();
            minedfa.push_back(node(preid, '-', nextid));
            minedfa.push_back(node(nextid, '-', preid));
            staids.push(nextid);
            break;
        default:
            strs.push(ch);
            staids.push(Staid++);
            break;
        }
    }
    char ch = strs.top();
    while (ch != '$')
    {
        int nextid = staids.top();
        staids.pop();
        int preid = staids.top();
        if (ch != '#')
        {
            minedfa.push_back(node(preid, ch, nextid));
        }
        strs.pop();
        ch = strs.top();
    }
}
void MyNFA::shownfa()
{
    sort(minedfa.begin(), minedfa.end(), cmp);
    cout << endl;
    for (auto &i : minedfa)
    {
        if (i.input == '-')
        {
            cout << i.fromid << " # " << i.endid << endl;
        }
        else

        {
            cout << i.fromid << " " << i.input << " " << i.endid << endl;
        }
    }

    cout << "\n==================================\n\n\n";
    for (auto &i : minedfa)
    {
        cout << i.fromid << "--[" << i.input << "]-->" << i.endid << endl;
    }

    cout << "start:"
         << "0\n";
    cout << "end:" << (*(minedfa.rbegin())).endid << "\n";
}