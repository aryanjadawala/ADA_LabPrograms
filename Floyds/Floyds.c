#include <stdio.h>

void Floyds(int n, int cost[50][50], int A[50][50])
{
    int i, j, k;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            A[i][j] = cost[i][j];

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
}

int main() {
    int n, i, j;
    int cost[50][50], A[50][50];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix (use 999 for infinity):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = 999;
            }
        }
    }
    Floyds(n, cost, A);
    printf("\nThe all-pairs shortest path matrix is:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if (A[i][j] == 999) printf("INF ");
            else printf("%d  ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
