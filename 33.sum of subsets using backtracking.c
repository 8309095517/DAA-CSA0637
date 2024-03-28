#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function prototypes
void subsetSum(int set[], int n, int sum);
void subsetSumUtil(int set[], int subset[], int n, int subSize, int total, int nodeCount, int sum);

// Function to print subsets having the given sum
void subsetSum(int set[], int n, int sum) {
    int subset[MAX_SIZE];
    subsetSumUtil(set, subset, n, 0, 0, 0, sum);
}

// Recursive utility function to find subsets with the given sum
void subsetSumUtil(int set[], int subset[], int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        // Print the current subset
        for (int i = 0; i < subSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        // Exclude previously added item and consider next candidate
        subsetSumUtil(set, subset, n, subSize - 1, total - set[nodeCount], nodeCount + 1, sum);
        return;
    } else {
        // Generate nodes along the breadth
        for (int i = nodeCount; i < n; i++) {
            subset[subSize] = set[i];
            // Consider next level node (along depth)
            subsetSumUtil(set, subset, n, subSize + 1, total + set[i], i + 1, sum);
        }
    }
}

// Main function
int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 35;
    printf("Subsets with sum %d are:\n", sum);
    subsetSum(set, n, sum);
    return 0;
}
