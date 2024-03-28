#include <stdio.h>

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int left = 0;
    int right = n - 1;
    int found = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            found = mid;
            break;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    if (found != -1)
        printf("Element %d is present at index %d\n", target, found);
    else
        printf("Element %d is not present in the array\n", target);
    
    return 0;
}
