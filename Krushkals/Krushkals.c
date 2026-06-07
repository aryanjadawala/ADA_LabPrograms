#include <stdio.h>

struct edge {
    int s, e, cost;
};

int cost = 0;
int grp[100];

int find(int x) {
    if (x == grp[x])
        return x;
    return grp[x] = find(grp[x]);
}

void merge(int x, int y, int c) {
    int gx = find(x);
    int gy = find(y);
    if (gx != gy) {
        grp[gy] = gx;
        cost += c;
    }
}

int main() {
    struct edge a[100];
    int n;

    printf("Enter the number of edges: ");
    scanf("%d", &n);

    printf("Enter src, dest and cost for following\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].s);
        scanf("%d", &a[i].e);
        scanf("%d", &a[i].cost);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].cost > a[j].cost) {
                struct edge t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        grp[i] = i;
    }
    for (int i = 0; i < n; i++) {
        merge(a[i].s, a[i].e, a[i].cost);
    }
    printf("\nFor the total cost is: %d\n", cost);
    return 0;
}
