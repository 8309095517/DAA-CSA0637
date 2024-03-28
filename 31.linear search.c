#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index of the key if found
        }
    }
    return -1;  // Return -1 if key is not found
}

int main() {
    int arr[] = {2, 5, 7, 9, 11, 15, 18, 22, 25};  // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int key, index;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform linear search
    index = linearSearch(arr, n, key);

    // Print result
    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
