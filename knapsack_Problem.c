#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    int i, w;


    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];  
}

int main() {
    int n, W;
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights of %d items:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of %d items:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, wt, val, n);

    printf("Maximum value in knapsack = %d\n", maxValue);

    return 0;
}
