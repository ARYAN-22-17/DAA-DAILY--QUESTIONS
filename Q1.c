
#include <stdio.h>

int main() {
    int n, digit;
    int sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;
        sum += digit;
        n = n / 10;
    }

    printf("Missing digit: %d\n", 45 - sum);

    return 0;
}
