#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n; // Number of cities
int dist[MAX_CITIES][MAX_CITIES]; // Distance matrix
int dp[MAX_CITIES][1 << MAX_CITIES]; // DP table

// Function to recursively solve TSP
int tsp(int current, int mask) {
    // Base case: If all cities have been visited
    if (mask == (1 << n) - 1) {
        return dist[current][0]; // Return to the starting city
    }

    // If result for current city and mask is already calculated, return it
    if (dp[current][mask] != -1) {
        return dp[current][mask];
    }

    int min_cost = INT_MAX;

    // Try visiting each unvisited city
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) { // If next city is not visited
            int cost = dist[current][next] + tsp(next, mask | (1 << next));
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }

    // Store the result for current city and mask
    dp[current][mask] = min_cost;
    return min_cost;
}

int main() {
    printf("Enter the number of cities (maximum %d): ", MAX_CITIES);
    scanf("%d", &n);

    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize DP table with -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0 and initially visit only city 0
    int min_cost = tsp(0, 1);

    printf("Minimum cost of the tour: %d\n", min_cost);

    return 0;
}
