#include <stdio.h>
#include <stdlib.h>

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Compare function to sort items by value-to-weight ratio in descending order
int compare(const void *a, const void *b) {
    double ratio_a = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio_b = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio_b > ratio_a) ? 1 : -1;
}

// Function to solve the Knapsack problem using greedy technique
void knapsack(int capacity, struct Item items[], int n) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compare);

    int current_weight = 0;
    double final_value = 0.0;

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the entire item won't exceed capacity, add it entirely
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            final_value += items[i].value;
        }
        // If adding the entire item would exceed capacity, add fraction of it
        else {
            int remaining_weight = capacity - current_weight;
            final_value += items[i].value * ((double)remaining_weight / items[i].weight);
            break;
        }
    }

    // Print the final value of items in the knapsack
    printf("Maximum value in the knapsack: %.2lf\n", final_value);
}

int main() {
    int capacity, n;

    // Input the capacity of the knapsack and the number of items
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the value and weight of each item
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Solve the Knapsack problem
    knapsack(capacity, items, n);

    return 0;
}
