#include <stdio.h>

// Function to check if a number is prime recursively
int isPrime(int n, int divisor) {
    if (n <= 2)
        return (n == 2);
    if (n % divisor == 0)
        return 0;
    if (divisor * divisor > n)
        return 1;
    return isPrime(n, divisor + 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num <= 1)
        printf("%d is not a prime number.\n", num);
    else if (isPrime(num, 2))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    
    return 0;
}
