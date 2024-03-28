#include <stdio.h>

// Function to recursively reverse a number
int reverseNumber(int num, int reversedNum) {
    // Base case: when the number becomes 0, return the reversed number
    if (num == 0)
        return reversedNum;
    else {
        // Extract the last digit of the number
        int lastDigit = num % 10;
        // Append the last digit to the reversed number
        reversedNum = reversedNum * 10 + lastDigit;
        // Recursive call with the remaining digits
        return reverseNumber(num / 10, reversedNum);
    }
}

int main() {
    int num;
    printf("Enter a number to reverse: ");
    scanf("%d", &num);

    // Call the function to reverse the number recursively
    int reversed = reverseNumber(num, 0);

    printf("Reverse of the number: %d\n", reversed);

    return 0;
}
