#include <stdio.h>
#include <string.h>
#define maxn 10005
int num[maxn];
int main()
{
    char str[maxn];
    gets(str);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < strlen(str); i++)
    {
        num[str[i]]++;
    }
    for (int i = 0; i < 1005; i++)
    {
        if (num[i])
        {
            printf("%c :%d\n", i, num[i]);
        }
    }
}