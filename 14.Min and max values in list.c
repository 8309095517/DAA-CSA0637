#include <stdio.h>

int main() {
    int numbers[] = {5, 10, 3, 8, 15};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("List of numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("Minimum and maximum value sequence for each number:\n");
    for (int i = 0; i < n; i++) {
        int min_val = numbers[i];
        int max_val = numbers[i];
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < min_val) {
                min_val = numbers[j];
            }
            if (numbers[j] > max_val) {
                max_val = numbers[j];
            }
            printf("(%d, %d) ", min_val, max_val);
        }
        printf("\n");
    }
    
    return 0;
}
