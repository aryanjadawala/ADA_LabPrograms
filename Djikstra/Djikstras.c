#include <stdio.h>

int main() {
    int n, cost[20][20], dist[20];
    int visited[20]; // Changed 's' to 'visited' to match your logic
    int i, j, source, u, min;

    printf("Enter number of vertices\n");
    scanf("%d", &n);

    printf("Enter the cost matrix\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    printf("Enter source vertex\n");
    scanf("%d", &source);

    for(i=1; i<=n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    visited[source] = 1;
    dist[source] = 0;

    for(i=1; i<=n; i++) {
        min = 999;
        for(j=1; j<=n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(j=1; j<=n; j++) {
            if(!visited[j] && (min + cost[u][j] < dist[j])) {
                dist[j] = min + cost[u][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source);
    for(i=1; i<=n; i++) {
        printf("to vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}
