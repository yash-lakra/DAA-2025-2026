#include <stdio.h>

int countWays(int coins[], int n, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 5;

    printf("Number of ways = %d\n", countWays(coins, n, amount));

    return 0;
}