#include <stdio.h>

// Function prototype
void generateFactors(int n, int i);

// Function to generate factors of n
void generateFactors(int n, int i) {
    if (i > n)
        return;

    if (n % i == 0)
        printf("%d ", i);

    generateFactors(n, i + 1);
}

// Main function
int main() {
    int n;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print the factors of n
    printf("Factors of %d are: ", n);
    generateFactors(n, 1);

    return 0;
}
