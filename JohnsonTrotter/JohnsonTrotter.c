#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    int dir;
    struct Node *next;
} N;
N* create(int n) {
    N *h = NULL, *t = NULL;
    for (int i = 1; i <= n; i++) {
        N *p = (N*)malloc(sizeof(N));
        p->val = i;
        p->dir = 0;
        p->next = NULL;
        if (!h) h = t = p;
        else {
            t->next = p;
            t = p;
        }
    }
    return h;
}
void print(N* h) {
    while (h) {
        printf("%d%s ", h->val, (h->dir == 0 ? "<-" : "->"));
        h = h->next;
    }
    printf("\n");
}
N* findMobile(N* h) {
    N *m = NULL;
    N *curr = h;
    N *prev = NULL;
    while (curr) {
        if (curr->dir == 0 && prev != NULL) {
            if (curr->val > prev->val) {
                if (!m || curr->val > m->val) m = curr;
            }
        }
        if (curr->dir == 1 && curr->next != NULL) {
            if (curr->val > curr->next->val) {
                if (!m || curr->val > m->val) m = curr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return m;
}

void flipDirections(N* h, int mobileVal) {
    N* curr = h;
    while (curr) {
        if (curr->val > mobileVal) {
            curr->dir = !curr->dir;
        }
        curr = curr->next;
    }
}

void swapNodes(N* a, N* b) {
    int tempVal = a->val;
    int tempDir = a->dir;
    a->val = b->val;
    a->dir = b->dir;
    b->val = tempVal;
    b->dir = tempDir;
}

int main() {
    int n;
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);
    N* h = create(n);
    printf("\nStarting Permutation:\n");
    print(h);
    N* m;
    while ((m = findMobile(h)) != NULL) {
        int mobileVal = m->val;
        if (m->dir == 0) {
            N* prev = h;
            while (prev->next != m) prev = prev->next;
            swapNodes(m, prev);
        } else {
            swapNodes(m, m->next);
        }
        flipDirections(h, mobileVal);
        print(h);
    }

    return 0;
}