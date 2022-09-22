#include <bits/stdc++.h>
using namespace std;
void GetNext_val(char T[], int *nextval)
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (T[i] != '\0')
    {
        if (j == 0 || T[i] == T[j])
        {
            ++j;
            ++i;
            if (T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}
void get_next(char T[], int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (T[i] != '\0')
    {
        if (j == 0 || T[i] == T[j])
        {
            ++j;
            ++i;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int KMP(int start, char S[], char T[]) /*这里我们默认数组第一个位置
                                       也就是S[0]和T[0]存的是数组的长度*/
{
    int i = start, j = 0;
    int next[255];
    get_next(T, next);
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (j == 0 || S[i] == T[j])
        {
            i++; //继续对下一个字符比较
            j++; //模式串向右滑动
        }
        else
            j = next[j];
    }
    if (T[j] == '\0')
        return (i - T[0]); //匹配成功返回下标
    else
        return -1; //匹配失败返回-1
}
//没找到
