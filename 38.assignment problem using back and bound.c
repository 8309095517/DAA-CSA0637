#include <stdio.h>
#include <limits.h>

#define N 4

// Function prototypes
void assignTasks(int costMatrix[N][N]);
int minCost(int costMatrix[N][N], int rowMask, int colMask, int row);

// Function to find the minimum cost assignment using branch and bound
void assignTasks(int costMatrix[N][N]) {
    int rowMask = 0, colMask = 0;
    int minAssignmentCost = minCost(costMatrix, rowMask, colMask, 0);
    printf("Minimum cost for the assignment: %d\n", minAssignmentCost);
}

// Function to find the minimum cost recursively
int minCost(int costMatrix[N][N], int rowMask, int colMask, int row) {
    if (row == N)
        return 0;

    int minCost = INT_MAX;
    for (int col = 0; col < N; col++) {
        if (!(colMask & (1 << col))) {
            int newCost = costMatrix[row][col] + minCost(costMatrix, rowMask | (1 << row), colMask | (1 << col), row + 1);
            if (newCost < minCost)
                minCost = newCost;
        }
    }
    return minCost;
}

// Main function
int main() {
    // Example cost matrix representing the cost of assigning each task to each agent
    int costMatrix[N][N] = { {9, 2, 7, 8},
                             {6, 4, 3, 7},
                             {5, 8, 1, 8},
                             {7, 6, 9, 4} };

    assignTasks(costMatrix);
    return 0;
}
