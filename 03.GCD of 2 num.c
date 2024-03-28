#include <stdio.h>

// Function to calculate GCD using recursive factorization
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("GCD is not defined for negative numbers.\n");
    } else {
        int result = gcd(num1, num2);
        printf("The GCD of %d and %d is: %d\n", num1, num2, result);
    }

    return 0;
}
