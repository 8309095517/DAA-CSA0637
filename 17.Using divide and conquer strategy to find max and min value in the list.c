#include <stdio.h>

#define MAX_SIZE 100

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, min1, max2, min2;

    // Base case: If there is only one element
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    // Base case: If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // Divide the array into two halves and recursively find max and min in each half
    mid = (low + high) / 2;
    findMaxMin(arr, low, mid, &max1, &min1);
    findMaxMin(arr, mid + 1, high, &max2, &min2);

    // Compare the max and min of two halves
    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main() {
    int arr[MAX_SIZE];
    int n, max, min;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find maximum and minimum values in the array
    findMaxMin(arr, 0, n - 1, &max, &min);

    // Print the maximum and minimum values
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
