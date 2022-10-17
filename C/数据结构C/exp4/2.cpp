#include <stdio.h>
#include <string.h>
#define maxn 105
int martix[maxn][maxn];
int max_col[maxn];
int min_row[maxn];
int main()
{
    memset(max_col, -0x3f, sizeof(max_col));
    memset(min_row, 0x3f, sizeof(min_row));
    //输入矩阵
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &martix[i][j]);
            if (martix[i][j] > max_col[j])
            {
                max_col[j] = martix[i][j];
            }
            if (martix[i][j] < min_row[i])
            {
                min_row[i] = martix[i][j];
            }
        }
    }
    printf("row col ele :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (martix[i][j] == min_row[i] && martix[i][j] == max_col[j])
            {
                printf("%-3d %-3d %-3d\n", i, j, martix[i][j]);
            }
        }
    }
}