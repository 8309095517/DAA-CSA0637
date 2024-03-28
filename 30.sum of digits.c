#include <stdio.h>

int main() {
    int num, sum = 0, digit;
    
    // Input number from user
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Calculate sum of digits
    while (num > 0) {
        digit = num % 10;  // Extract the last digit
        sum += digit;      // Add the last digit to the sum
        num /= 10;         // Remove the last digit from the number
    }
    
    // Display the sum of digits
    printf("Sum of digits: %d\n", sum);
    
    return 0;
}
