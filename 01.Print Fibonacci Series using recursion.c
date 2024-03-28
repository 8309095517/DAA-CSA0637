#include <stdio.h>

void fibonacci(int n, int a, int b) {
    if (n == 0)
        return;
    printf("%d ", a);
    fibonacci(n - 1, b, a + b);
}

int main() {
    int n = 10;
    printf("Fibonacci Series up to %d terms:\n", n);
    fibonacci(n, 0, 1);
    return 0;
}
