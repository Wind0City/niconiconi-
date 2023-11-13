#include <stdio.h>
#include <string.h>
const int maxn = 1e3;
int max_need[maxn][maxn]; // 最大
int had_allo[maxn][maxn]; // 已分配
int m_h_need[maxn][maxn]; // 需要
int avaliable[maxn];      // 资源个数
int mine_request[maxn];   // request选项
bool jud[maxn];           // 资源是否完成
/*******************************************************/
int max_need_2[maxn][maxn]; // 最大
int had_allo_2[maxn][maxn]; // 已分配
int m_h_need_2[maxn][maxn]; // 需要
int avaliable_2[maxn];      // 资源个数
int mine_request_2[maxn];   // request选项
bool jud_2[maxn];
/******************************************************/
int ansf[maxn];  // 最终答案安全序列
int num_pcb;     // 进程个数
int num_res;     // 资源个数
int mine_choice; // request的选项

int tot;    // 用来给答案安全序列计数
void init() // 初始化,重新拷贝
{
    for (int i = 1; i <= num_res; i++)
    {
        avaliable[i] = avaliable_2[i];
    }
    for (int i = 1; i <= num_pcb; i++)
    {

        jud[i] = jud_2[i];
        for (int j = 1; j <= num_res; j++)
        {
            max_need[i][j] = max_need_2[i][j];
            had_allo[i][j] = had_allo_2[i][j];
            m_h_need[i][j] = m_h_need_2[i][j];
        }
    }
}
void input_ava() // 输入创建进程
{
    printf("\n输入资源个数:");
    scanf("%d", &num_res);
    for (int i = 1; i <= num_res; i++)
    {
        printf("\n%d号资源个数:", i);
        scanf("%d", &avaliable_2[i]);
    }
    printf("创建完成\n");
}
void input_pcb() // 输入初始化进程
{
    printf("输入进程个数");
    scanf("%d", &num_pcb);
    printf("进程对应每个资源的最大需求:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        jud[i] = false;
        printf("\n%d号进程:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d号资源\n", j);
            scanf("%d", &max_need_2[i][j]);
        }
    }
    printf("进程对应每个资源的已分配:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        printf("\n%d号进程:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d号资源\n", j);
            scanf("%d", &had_allo_2[i][j]);
            avaliable_2[j] -= had_allo_2[i][j]; // 对应的资源数减少
        }
    }
    printf("进程对应每个资源的需求:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        printf("\n%d号进程:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d号资源:", j);
            m_h_need_2[i][j] = max_need_2[i][j] - had_allo_2[i][j]; // 计算得出need矩阵
            printf("%d\n", m_h_need_2[i][j]);
        }
    }
}
bool isdone() // 判断所有的进程是否都已结束
{
    for (int i = 1; i <= num_pcb; i++)
    {
        if (!jud[i])
        {
            return false;
        }
    }
    return true;
}
bool isdone_2() // real
{
    for (int i = 1; i <= num_pcb; i++)
    {
        if (!jud_2[i])
        {
            return false;
        }
    }
    return true;
}
bool issafe() // 安全算法
{
    while (!isdone()) // 在所有进程没完成前
    {
        bool jjj = false; // 用来标记是否能找到一个满足当前资源个数的进程
        for (int i = 1; i <= num_pcb; i++)
        {
            if (!jud[i])
            {
                bool flag = false;                 // 判断当前进程是否满足
                for (int j = 1; j <= num_res; j++) // 遍历所有资源数
                {
                    if (m_h_need[i][j] > avaliable[j]) // 有一项资源数不够
                    {
                        flag = true; // 这个进程不满足
                    }
                }
                if (!flag) // 当前进程满足,运行
                {

                    for (int j = 1; j <= num_res; j++) // 返还资源
                    {
                        avaliable[j] += had_allo[i][j];
                    }
                    jud[i] = true;
                    printf("%d!,done!\n", i - 1);
                    ansf[tot++] = i; // 将此进程推入安全序列中
                    jjj = true;      // 找到一个满足的进程
                }
                else
                {
                    continue;
                }
            }
        }
        if (!jjj) // 一个满足的进程都没找到
        {
            return false; // 寄了
        }
    }
    return true;
}
int bank()
{
    for (int i = 1; i <= num_res; i++) // 遍历所有的资源
    {
        if (mine_request[i] > max_need[mine_choice][i])
        {
            return 1; // 需要的资源数超过=它本身宣布的最大值
        }
        if (mine_request[i] > avaliable[i])
        {
            return 2; // 对应的资源不够
        }
    }
    bool isjud = false;                // 判断试探性分布是否直接将它完成
    for (int i = 1; i <= num_res; i++) // 试探性分布
    {
        avaliable[i] -= mine_request[i];             // 总资源数对应分配
        had_allo[mine_choice][i] += mine_request[i]; // 已分配的资源数增加
        m_h_need[mine_choice][i] -= mine_request[i]; // 需求减少
        if (m_h_need[mine_choice][i] == 0)
        {
            isjud = true;
        }
    }
    if (isjud)
    {
        jud[mine_choice] = true;
        for (int i = 1; i <= num_res; i++)
        {
            avaliable[i] += had_allo[mine_choice][i];
        }
        ansf[tot++] = mine_choice;
        printf("%d!,done!\n", mine_choice - 1);
    }
    if (issafe()) // 执行安全性算法
    {
        return 3; // 安全返回3
    }
    return 4; // 否则返回4
}
int main()
{
    init();
    input_ava();
    input_pcb();
    tot = 1;
    while (!isdone_2())
    {
        init();
        printf("\n进程对应每个资源的最大需求:\n");
        for (int i = 1; i <= num_pcb; i++)
        {
            printf("\n%d号进程:\n", i);
            for (int j = 1; j <= num_res; j++)
            {
                printf("%d号资源:", j);
                printf("%d \n", max_need_2[i][j]);
            }
        }
        printf("进程对应每个资源的已分配:\n");
        for (int i = 1; i <= num_pcb; i++)
        {
            printf("\n%d号进程:\n", i);
            for (int j = 1; j <= num_res; j++)
            {
                printf("%d号资源:", j);
                printf("%d\n", had_allo_2[i][j]);
            }
        }
        printf("进程对应每个资源的需求:\n");
        for (int i = 1; i <= num_pcb; i++)
        {
            printf("\n%d号进程:\n", i);
            for (int j = 1; j <= num_res; j++)
            {
                printf("%d号资源:", j);
                printf("%d\n", m_h_need_2[i][j]);
            }
        }
        printf("进程是否已完成:\n");
        for (int i = 1; i <= num_pcb; i++)
        {
            printf("%d号进程 : %d\n", i, jud_2[i]);
        }
        for (int i = 1; i <= num_res; i++)
        {
            printf("\n%d号资源剩余: %d\n", i, avaliable_2[i]);
        }
        printf("\n选择进程,输入0结束程序:");
        scanf("%d", &mine_choice);
        if (mine_choice == 0)
        {
            break;
        }
        printf("\n输入对此进程的reques:\n");
        for (int i = 1; i <= num_res; i++)
        {
            printf("\n需要%d号资源:", i);
            scanf("%d", &mine_request[i]);
        }
        tot = 1;
        int last = bank();
        if (last == 1)
        {
            printf("\n它所需要的资源数已超过它所宣布的最大值,等待\n");
        }
        else if (last == 2)
        {
            printf("\n尚无足够资源,等待\n");
        }
        else if (last == 3)
        {
            printf("处于安全状态,一个可能的安全序列为:\n");
            for (int i = 1; i < tot; i++)
            {
                printf("%2d->", ansf[i] - 1);
            }
            bool flag = false;
            for (int i = 1; i <= num_res; i++) // 对数据做出改变
            {
                had_allo_2[mine_choice][i] += mine_request[i];
                m_h_need_2[mine_choice][i] -= mine_request[i];
                avaliable_2[i] -= mine_request[i];
                if (had_allo_2[mine_choice][i] != max_need[mine_choice][i])
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                jud_2[mine_choice] = 1;
                for (int i = 1; i <= num_res; i++)
                {
                    avaliable_2[i] += had_allo_2[mine_choice][i];
                }
            }
        }
        else if (last == 4)
        {
            printf("不安全!,等待\n");
        }
        printf("\n***********************************************************\n");
    }
    for (int i = 1; i <= num_res; i++)
    {
        printf("\n%d号资源剩余: %d\n", i, avaliable_2[i]);
    }
    return 0;
}