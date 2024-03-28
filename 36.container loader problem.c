#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

// Function prototypes
void containerLoader(int items[], int numItems, int containerCapacity);

// Function to compute container loading
void containerLoader(int items[], int numItems, int containerCapacity) {
    int containers[MAX_CONTAINERS] = {0}; // Array to store remaining capacity of each container
    int containerCount = 0;

    for (int i = 0; i < numItems; i++) {
        int itemWeight = items[i];
        int j;
        for (j = 0; j < containerCount; j++) {
            if (containers[j] >= itemWeight) {
                containers[j] -= itemWeight;
                break;
            }
        }
        if (j == containerCount) {
            if (containerCount == MAX_CONTAINERS) {
                printf("Not enough containers to accommodate all items\n");
                return;
            }
            containers[containerCount++] = containerCapacity - itemWeight;
        }
    }

    printf("Items have been loaded into %d containers as follows:\n", containerCount);
    for (int i = 0; i < containerCount; i++) {
        printf("Container %d: Remaining capacity = %d\n", i + 1, containers[i]);
    }
}

// Main function
int main() {
    int items[MAX_ITEMS], numItems, containerCapacity;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Input the weights of the items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    // Input the capacity of each container
    printf("Enter the capacity of each container: ");
    scanf("%d", &containerCapacity);

    // Compute container loading
    containerLoader(items, numItems, containerCapacity);

    return 0;
}
