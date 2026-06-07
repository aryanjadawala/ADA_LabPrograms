#include <stdio.h>

#define INF 999
#define MAX 50

void prims(int n, int cost[MAX][MAX]) {
    int parent[MAX], key[MAX], mstSet[MAX];
    int i, v, count, u, min, totalcost = 0;

    for (i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < n - 1; count++) {
        min = INF;
        for (v = 0; v < n; v++) {
            if (mstSet[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;

        for (v = 0; v < n; v++) {
            if (cost[u][v] != 0 && mstSet[v] == 0 && cost[u][v] < key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    printf("\nEdge \tWeight\n");
    for (i = 1; i < n; i++) {
        printf("%d - %d \t %d\n", parent[i], i, cost[i][parent[i]]);
        totalcost += cost[i][parent[i]];
    }
    printf("\nTotal minimum Cost: %d\n", totalcost);
}

int main() {
    int n, cost[MAX][MAX];
    printf("Enter no of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency matrix (use 999 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}