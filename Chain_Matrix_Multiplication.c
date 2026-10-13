#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int dp[n][n];  
    int i, j, k, L, cost;

    for (i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i <= n - L; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n, i;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions for %d matrices (n+1 integers):\n", n);
    printf("Example: for matrices A1(10x20), A2(20x30), A3(30x40), enter: 10 20 30 40\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int minMultiplications = matrixChainOrder(p, n + 1);

    printf("Minimum number of scalar multiplications required: %d\n", minMultiplications);

    return 0;
}
