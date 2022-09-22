#include <bits/stdc++.h>
using namespace std;
int a[100005];
int v[100005] = {0};
int s[100005];
int n;
int jy;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        jy = 0;
        int temp;
        memset(v, 0, sizeof(v));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            if (i > 1)
            {
                if (s[i] != s[i - 1])
                {
                    jy = -1;
                }
                else
                {
                    temp = s[i];
                }
            }
        }
        if (jy == 0 && temp <= n && temp >= 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
            {
                if (!v[i] && i != s[i])
                {
                    v[i] = 1;
                    printf("%d ", i);
                    continue;
                }
                for (int j = 1; j <= n; j++)
                {
                    if (!v[j] && j != s[i])
                    {
                        v[j] = 1;
                        printf("%d ", j);
                        break;
                    }
                }
            }
            printf("\n");
        }
    }
}