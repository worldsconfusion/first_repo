#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
int main()
{   int n,W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int profit[n],weight[n];
    printf("Enter profits and corresponding weights: ");
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &profit[i]);
         scanf("%d", &weight[i]);
    }

    printf("Enter weight limit:");
   scanf("%d",&W);
    printf("%d", knapSack(W, weight, profit, n));
    return 0;
}
