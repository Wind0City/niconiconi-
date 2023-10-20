#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <unordered_map>
using namespace std;

struct pcb
{
    string name;
    unordered_map<string, int> maxneed;  // �������
    unordered_map<string, int> allocaed; // �Ѿ�����
    unordered_map<string, int> max_all;  // �����Ҫ���������ߵĲ�ֵ
    bool jud;                            // �ж��Ƿ����
};
unordered_map<string, int> resource; // ��Դ��(������)
unordered_map<string, int> availabe; // ��Դ(�����Ĳ���)
vector<pcb> pcbs;                    // ������
vector<pcb> pcb_or;                  // �����Ĳ���
vector<string> ans;
void input_resource() // ������Դ��
{
    printf("\n================��Դ����==================\n");
    int num;
    printf("\n��Դ������:");
    cin >> num;
    printf("\n���������Դ���Լ���Ŀ:");
    string name;
    int number;
    for (int i = 1; i <= num; i++)
    {
        printf("\n%2d����Դ", i);
        printf("\n��Դ����:");
        cin >> name;
        printf("\n��Դ����:");
        cin >> number;
        availabe[name] = number;
    }
    printf("\n================��Դ�������==================\n");
}
void input_pcb() // �������
{
    printf("\n================���̴���===================\n");
    int num;
    printf("\n������Ŀ:");
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        pcb temp;
        temp.jud = false;
        printf("%d�Ž���", i);
        printf("������:");
        cin >> temp.name;
        printf("���̵����������Դ��\n");
        int count;
        for (auto &p : availabe)
        {
            cout << p.first << ":";
            cin >> count;
            temp.maxneed[p.first] = count;
        }
        printf("���̵��ѷ�����Դ\n");
        for (auto &p : availabe)
        {
            cout << p.first << ":";
            cin >> count;
            temp.allocaed[p.first] = count;
            p.second -= count;
        }
        printf("\n��໹��Ҫ(����ó�)\n");
        for (auto &p : availabe)
        {
            temp.max_all[p.first] = temp.maxneed[p.first] - temp.allocaed[p.first];
            cout << p.first << ":" << temp.max_all[p.first] << "\n";
        }
        pcb_or.push_back(temp);
    }
    printf("\n================���̴����ɹ�===================\n");
}
bool done() // �жϳ����Ƿ����н���
{
    for (auto &p : pcbs)
    {
        if (p.jud == false)
        {
            return false;
        }
    }
    return true;
}
void show_pcb() // չʾĿǰ������Ϣ
{
    printf("\n======================================\n");
    for (auto &p : pcb_or)
    {
        printf("\n������:");
        cout << p.name;
        if (p.jud == true) // �����Ѿ�����
        {
            printf("\n�ý����ѽ���");
            continue;
        }
        printf("\n����Դ���������:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.maxneed[i.first]);
        }
        printf("\n");
        printf("\n�ѷ�����Դ:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.allocaed[i.first]);
        }
        printf("\n");
        printf("\n��໹��Ҫ:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.max_all[i.first]);
        }
        printf("\n");
    }
    printf("\n======================================\n");
}
void shoresource() // չʾ��Դ��Ϣ
{
    printf("\n=================ϵͳʣ����Դ================\n");
    for (auto &p : availabe)
    {
        cout << p.first << " : " << p.second << "\n";
    }
    printf("\n======================================\n");
}
bool issafe()
{
    while (!done())
    {
        bool jjj = false;
        for (auto &p : pcbs)
        {
            if (p.jud == false) // δ����
            {
                bool flag = false;
                for (auto &i : resource) // ������Դ��
                {
                    if (p.max_all[i.first] > i.second)
                    {
                        flag = true;
                    }
                }
                if (!flag) // ������
                {
                    for (auto &i : resource) // ������Դ��
                    {
                        i.second += p.max_all[i.first];
                        p.jud = true;
                    }
                    ans.push_back(p.name);
                    jjj = true; // �ҵ�һ��
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if (!jjj) // һ����û�ҵ�
        {
            return false;
        }
    }
    return true;
}
int bank(unordered_map<string, int> &request, string &choice)
{
    for (auto &p : pcbs)
    {
        if (p.name == choice)
        {
            for (auto &i : p.max_all)
            {
                if (request[i.first] > i.second)
                {
                    return 1; // ������Ҫ����Դ���ѳ����������������ֵ
                }
            }
            for (auto &i : resource)
            {
                if (request[i.first] > i.second)
                {
                    return 2; // �����㹻��Դ
                }
            }
            for (auto &i : resource) // ��̽�Է���
            {
                i.second -= request[i.first];
                p.allocaed[i.first] += request[i.first];
                p.maxneed[i.first] -= request[i.first];
            }
            if (issafe())
            {
                return 3;
            }
            else
            {
                return 4;
            }
            break;
        }
    }
}
int main()
{
    input_resource();
    input_pcb();
    /*show_pcb();
    shoresource();*/

    unordered_map<string, int> request;
    while (1)
    {
        printf("\n***********************************************************\n");
        pcbs = pcb_or;
        resource = availabe; // ��ֵ����һ��
        show_pcb();
        shoresource();
        string choice;
        printf("ѡ�����:(����0�˳�)");
        cin >> choice;
        if (choice == "0")
        {
            break;
        }

        printf("����Դ˽��̵�request:");
        printf("\n======================================\n");
        int numb;
        for (auto &p : availabe)
        {
            cout << p.first << ":";
            cin >> numb;
            request[p.first] = numb;
        }
        int last = bank(request, choice);

        if (last == 1)
        {
            printf("\n������Ҫ����Դ���ѳ����������������ֵ\n");
        }
        else if (last == 2)
        {
            printf("\n�����㹻��Դ\n");
        }
        else if (last == 3)
        {
            printf("���ڰ�ȫ״̬,һ�����ܵİ�ȫ����Ϊ:\n");
            for (auto i : ans)
            {
                cout << i << "-->";
            }
            cout << "\n";
        }
        else if (last == 4)
        {
            printf("����ȫ!\n");
        }
        printf("\n***********************************************************\n");
        getchar();
        ans.clear();
    
    }
    return 0;
}