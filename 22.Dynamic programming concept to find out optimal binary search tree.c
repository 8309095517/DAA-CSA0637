#include <stdio.h>

#define INF 9999
#define MAX_KEYS 10

void optimalBST(float p[], int n) {
    float dp[MAX_KEYS + 1][MAX_KEYS + 1];
    float cost[MAX_KEYS + 1][MAX_KEYS + 1];
    int root[MAX_KEYS][MAX_KEYS];

    for (int i = 0; i <= n; i++) {
        dp[i][i] = p[i];
        cost[i][i] = p[i];
        root[i][i] = i;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INF;
            cost[i][j] = cost[i][j - 1] + p[j];

            for (int r = i; r <= j; r++) {
                float temp = dp[i][r - 1] + dp[r + 1][j] + cost[i][j];
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Optimal Binary Search Tree:\n");
    printf("Root is key %d\n", root[0][n - 1]);
    printf("Average search time: %f\n", dp[0][n - 1]);
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float p[n + 1];
    printf("Enter the probabilities of searching for each key:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }

    optimalBST(p, n);

    return 0;
}
