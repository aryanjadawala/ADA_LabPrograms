#include <stdio.h>

int main()
{
    int n, w[50], p[50], m, a[50][50];
    int i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    printf("Enter the weights: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter the profits: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i <= n; i++)
        a[i][0] = 0;
    for (j = 0; j <= m; j++)
        a[0][j] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (j < w[i])
            {
                a[i][j] = a[i - 1][j];
            }
            else
            {
                if (a[i - 1][j] > (p[i] + a[i - 1][j - w[i]]))
                {
                    a[i][j] = a[i - 1][j];
                }
                else
                {
                    a[i][j] = p[i] + a[i - 1][j - w[i]];
                }
            }
        }
    }
    printf("Total profit: %d\n", a[n][m]);
    return 0;
}
