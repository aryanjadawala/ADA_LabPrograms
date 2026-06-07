#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int x[20], n;
int solutionCount = 0;

int placeQueen(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if ((x[j] == i) || (abs(j - k) == abs(x[j] - i)))
            return 0;
    }
    return 1;
}

void printSolution()
{
    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void nQueens(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (placeQueen(k, i))
        {
            x[k] = i;

            if (k == n)
                printSolution();
            else
                nQueens(k + 1);
        }
    }
}

void main()
{
    clock_t start, end;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    start = clock();
    nQueens(1);
    end = clock();
    if (solutionCount == 0)
        printf("\nNo Solution Exists\n");
    else
        printf("\nTotal Solutions = %d\n", solutionCount);

    double time_taken =
        (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;

    printf("Time Taken: %f ms\n", time_taken);
}
