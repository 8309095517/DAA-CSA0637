#include <stdio.h>
#include <math.h>


int countDigits(int number) {
    if (number == 0)
        return 0;
    else
        return 1 + countDigits(number / 10);
}

 
int isArmstrong(int number, int n) {
    if (number == 0)
        return 0;
    else
        return pow(number % 10, n) + isArmstrong(number / 10, n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int digits = countDigits(num);
    int sum = isArmstrong(num, digits);
    
    if (sum == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    
    return 0;
}
