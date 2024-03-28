#include <stdio.h>

// Function to print a single row of the pattern
void printPatternRow(int n, int i) {
    if (i > n)
        return;
    
    printf("%d ", i);
    printPatternRow(n, i + 1);
}

// Function to print the pattern recursively
void printPattern(int n) {
    if (n == 0)
        return;
    
    printPattern(n - 1);
    printPatternRow(n, 1);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPattern(n);

    return 0;
}
