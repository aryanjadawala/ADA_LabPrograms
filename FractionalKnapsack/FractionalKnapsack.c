#include<stdio.h>
struct item{
    int p;
    int w;
    float r;
    float x;
};
int main(){
    int n, m;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    struct item items[20], temp;
    for(int i=0; i<n; i++){
        printf("Enter weight of item %d: ", i+1);
        scanf("%d", &items[i].w);
        printf("Enter profit of item %d: ", i+1);
        scanf("%d", &items[i].p);
        items[i].x = 0;
        items[i].r = (float)items[i].p / items[i].w;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(items[j].r > items[i].r){
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    float remain = m, maxprofit = 0;
    for(int i=0; i<n; i++){
        if(items[i].w <= remain){
            items[i].x = 1;
            remain -= items[i].w;
            maxprofit += items[i].p;
        } else {
            items[i].x = remain / items[i].w;
            maxprofit += items[i].p * items[i].x;
            break;
        	}
    }
   
    printf("\nMaximum profit = %.2f\n", maxprofit);
}
