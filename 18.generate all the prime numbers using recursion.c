#include <stdio.h>

int isPrime(int num, int divisor) {
    if (num <= 2)
        return (num == 2) ? 1 : 0;
    if (num % divisor == 0)
        return 0;
    if (divisor * divisor > num)
        return 1;
    return isPrime(num, divisor + 1);
}

void generatePrimes(int n, int current) {
    if (current > n)
        return;
    
    if (isPrime(current, 2))
        printf("%d ", current);
    
    generatePrimes(n, current + 1);
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    generatePrimes(limit, 2);

    return 0;
}
