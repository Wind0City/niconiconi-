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
    unordered_map<string, int> maxneed;  // 最大需求
    unordered_map<string, int> allocaed; // 已经分配
    unordered_map<string, int> max_all;  // 最多需要：上面两者的差值
    bool jud;                            // 判断是否结束
};
unordered_map<string, int> resource; // 资源数
unordered_map<string, int> availabe;
vector<pcb> pcbs;
vector<string> ans;
void input_resource() // 输入资源数
{
    printf("\n================资源创建==================\n");
    int num;
    printf("\n资源种类数:");
    cin >> num;
    printf("\n输入各个资源名以及数目:");
    string name;
    int number;
    for (int i = 1; i <= num; i++)
    {
        printf("\n%2d号资源", i);
        printf("\n资源名字:");
        cin >> name;
        printf("\n资源个数:");
        cin >> number;
        resource[name] = number;
    }
    printf("\n================资源创建完成==================\n");
}
void input_pcb() // 输入进程
{
    printf("\n================进程创建===================\n");
    int num;
    printf("\n进程数目:");
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        pcb temp;
        temp.jud = false;
        printf("%d号进程", i);
        printf("进程名:");
        cin >> temp.name;
        printf("进程的最大需求资源数\n");
        int count;
        for (auto &p : resource)
        {
            cout << p.first << ":";
            cin >> count;
            temp.maxneed[p.first] = count;
        }
        printf("进程的已分配资源\n");
        for (auto &p : resource)
        {
            cout << p.first << ":";
            cin >> count;
            temp.allocaed[p.first] = count;
            p.second -= count;
        }
        printf("\n最多还需要(计算得出)\n");
        for (auto &p : resource)
        {
            temp.max_all[p.first] = temp.maxneed[p.first] - temp.allocaed[p.first];
            cout << p.first << ":" << temp.max_all[p.first] << "\n";
        }
        pcbs.push_back(temp);
    }
    printf("\n================进程创建成功===================\n");
}
bool done() // 判断程序是否都运行结束
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
void show_pcb() // 展示目前进程信息
{
    printf("\n======================================\n");
    for (auto &p : pcbs)
    {
        printf("\n进程名:");
        cout << p.name;
        if (p.jud == true) // 进程已经结束
        {
            printf("\n该进程已结束");
            continue;
        }
        printf("\n对资源的最大需求:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.maxneed[i.first]);
        }
        printf("\n");
        printf("\n已分配资源:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.allocaed[i.first]);
        }
        printf("\n");
        printf("\n最多还需要:\t");
        for (auto &i : resource)
        {
            cout << i.first;
            printf(":%d  ", p.max_all[i.first]);
        }
        printf("\n");
    }
    printf("\n======================================\n");
}
void shoresource() // 展示资源信息
{
    printf("\n=================系统剩余资源================\n");
    for (auto &p : resource)
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
            if (p.jud == false) // 未结束
            {
                bool flag = false;
                for (auto &i : resource) // 并且资源够
                {
                    if (p.max_all[i.first] > i.second)
                    {
                        flag = true;
                    }
                }
                if (!flag) // 都满足
                {
                    for (auto &i : resource) // 并且资源够
                    {
                        i.second += p.max_all[i.first];
                        p.jud = true;
                    }
                    ans.push_back(p.name);
                    jjj = true; // 找到一个
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if (!jjj) // 一个都没找到
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
                    return 1; // 它所需要的资源数已超过它所宣布的最大值
                }
            }
            for (auto &i : resource)
            {
                if (request[i.first] > i.second)
                {
                    return 2; // 尚无足够资源
                }
            }
            for (auto &i : resource) // 试探性分配
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
    show_pcb();
    shoresource();
    string choice;
    printf("选择进程:");
    cin >> choice;
    printf("输入对此进程的request:");
    printf("\n======================================\n");
    int numb;
    for (auto &p : resource)
    {
        cout << p.first << ":";
        cin >> numb;
        request[p.first] = numb;
    }
    int last = bank(request, choice);
    printf("\nhere?\n");
    getchar();
    if (last == 1)
    {
        printf("\n它所需要的资源数已超过它所宣布的最大值\n");
    }
    else if (last == 2)
    {
        printf("\n尚无足够资源\n");
    }
    else if (last == 3)
    {
        printf("处于安全状态,一个可能的安全序列为:\n");
        for (auto i : ans)
        {
            cout << i << "-->";
        }
        cout << "\n";
    }
    else if (last == 4)
    {
        printf("不安全!\n");
    }
    getchar();
    return 0;
}