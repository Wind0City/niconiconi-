#include <stdio.h>
#include <string.h>
const int maxn = 1e3;
int max_need[maxn][maxn]; // ���
int had_allo[maxn][maxn]; // �ѷ���
int m_h_need[maxn][maxn]; // ��Ҫ
int avaliable[maxn];      // ��Դ����
int mine_request[maxn];   // requestѡ��
int num_pcb;              // ���̸���
int num_res;              // ��Դ����
int mine_choice;          // request��ѡ��
bool jud[maxn];           // ��Դ�Ƿ����
int ansf[maxn];           // ���մ𰸰�ȫ����
int tot;                  // �������𰸰�ȫ���м���
void init()               // ��ʼ��
{
    memset(jud, 0, sizeof(jud)); // ������ȫ��ֵΪ0
    memset(max_need, 0, sizeof(max_need));
    memset(had_allo, 0, sizeof(had_allo));
    memset(m_h_need, 0, sizeof(m_h_need));
    memset(avaliable, 0, sizeof(avaliable));
    tot = 1;
}
void input_ava() // ���봴������
{
    printf("\n������Դ����:");
    scanf("%d", &num_res);
    for (int i = 1; i <= num_res; i++)
    {
        printf("\n%d����Դ����:", i);
        scanf("%d", &avaliable[i]);
    }
    printf("�������\n");
}
void input_pcb() // �����ʼ������
{
    printf("������̸���");
    scanf("%d", &num_pcb);
    printf("���̶�Ӧÿ����Դ���������:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        jud[i] = false;
        printf("\n%d�Ž���:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d����Դ\n", j);
            scanf("%d", &max_need[i][j]);
        }
    }
    printf("���̶�Ӧÿ����Դ���ѷ���:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        printf("\n%d�Ž���:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d����Դ\n", j);
            scanf("%d", &had_allo[i][j]);
            avaliable[j] -= had_allo[i][j]; // ��Ӧ����Դ������
        }
    }
    printf("���̶�Ӧÿ����Դ������:\n");
    for (int i = 1; i <= num_pcb; i++)
    {
        printf("\n%d�Ž���:\n", i);
        for (int j = 1; j <= num_res; j++)
        {
            printf("%d����Դ:", j);
            m_h_need[i][j] = max_need[i][j] - had_allo[i][j]; // ����ó�need����
            printf("%d\n", m_h_need[i][j]);
        }
    }
}
bool isdone() // �ж����еĽ����Ƿ��ѽ���
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
bool issafe() // ��ȫ�㷨
{
    while (!isdone()) // �����н���û���ǰ
    {
        bool jjj = false; // ��������Ƿ����ҵ�һ�����㵱ǰ��Դ�����Ľ���
        for (int i = 1; i <= num_pcb; i++)
        {
            if (!jud[i])
            {
                bool flag = false;                 // �жϵ�ǰ�����Ƿ�����
                for (int j = 1; j <= num_res; j++) // ����������Դ��
                {
                    if (m_h_need[i][j] > avaliable[j]) // ��һ����Դ������
                    {
                        flag = true; // ������̲�����
                    }
                }
                if (!flag) // ��ǰ��������,����
                {
                    for (int j = 1; j <= num_res; j++) // ������Դ
                    {
                        avaliable[j] += max_need[i][j];
                    }
                    jud[i] = true;
                    printf("%d!,done!\n", i);
                    ansf[tot++] = i; // ���˽������밲ȫ������
                    jjj = true;      // �ҵ�һ������Ľ���
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        if (!jjj) // һ������Ľ��̶�û�ҵ�
        {
            return false; // ����
        }
    }
    return true;
}
int bank()
{
    for (int i = 1; i <= num_res; i++) // �������е���Դ
    {
        if (mine_request[i] > max_need[mine_choice][i])
        {
            return 1; // ��Ҫ����Դ������=���������������ֵ
        }
        if (mine_request[i] > avaliable[i])
        {
            return 2; // ��Ӧ����Դ����
        }
    }
    bool isjud = false;                // �ж���̽�Էֲ��Ƿ�ֱ�ӽ������
    for (int i = 1; i <= num_res; i++) // ��̽�Էֲ�
    {
        avaliable[i] -= mine_request[i];             // ����Դ����Ӧ����
        had_allo[mine_choice][i] += mine_request[i]; // �ѷ������Դ������
        m_h_need[mine_choice][i] -= mine_request[i]; // �������
        if (m_h_need[mine_choice][i] > 0)
        {
            isjud = true;
        }
    }
    if (isjud)
    {
        jud[mine_choice] = true;
        printf("%d!,done!\n", mine_choice);
    }
    if (issafe()) // ִ�а�ȫ���㷨
    {
        return 3; // ��ȫ����3
    }
    return 4; // ���򷵻�4
}
int main()
{
    input_ava();
    input_pcb();
    for (int i = 1; i <= num_res; i++)
    {
        printf("\n%d�Ž���ʣ��: %d\n", i, avaliable[i]);
    }
    printf("\nѡ�����:");
    scanf("%d", &mine_choice);

    printf("\n����Դ˽��̵�reques:\n");
    for (int i = 1; i <= num_res; i++)
    {
        printf("\n��Ҫ%d����Դ:", i);
        scanf("%d", &mine_request[i]);
    }
    tot = 1;
    int last = bank();
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
        for (int i = 1; i <= num_pcb; i++)
        {
            printf("%2d->", ansf[i] - 1);
        }
    }
    else if (last == 4)
    {
        printf("����ȫ!\n");
    }
    printf("\n***********************************************************\n");
    getchar();
    return 0;
}