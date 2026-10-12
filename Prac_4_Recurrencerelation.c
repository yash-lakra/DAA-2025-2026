 #include <stdio.h>

long long int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("factorial of %d = %lld", n, factorial(n));
    return 0;
}