#include <stdio.h>
#define MAX 10
int main() {
    int n, i, j, graph[MAX][MAX], indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1, topo[MAX], k = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) indegree[j]++;
        }
    }
    for (i = 0; i < n; i++) if (indegree[i] == 0) queue[++rear] = i;
    while (front <= rear) {
        int v = queue[front++]; topo[k++] = v;
        for (j = 0; j < n; j++) {
            if (graph[v][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) queue[++rear] = j;
            }
        }
    }
    printf("Topological Order: ");
    for (i = 0; i < k; i++) printf("%d ", topo[i]);
    return 0;
}
