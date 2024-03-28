#include <stdio.h>

// Function to find the largest element of an array
int findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {10, 23, 6, 45, 90, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int largest = findLargest(arr, size);
    
    printf("The largest element of the array is: %d\n", largest);
    
    return 0;
}
