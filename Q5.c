
#include <stdio.h>

int main() {
    unsigned int n, temp;
    int ones = 0, zeros = 0;
    int consecutive = 0, maxConsecutive = 0;

    printf("Enter a number: ");
    scanf("%u", &n);

    temp = n;

    if (temp == 0) {
        zeros = 1;
    }

    while (temp > 0) {
        if (temp % 2 == 1) {
            ones++;
            consecutive++;

            if (consecutive > maxConsecutive) {
                maxConsecutive = consecutive;
            }
        } else {
            zeros++;
            consecutive = 0;
        }

        temp = temp / 2;
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Maximum consecutive 1s: %d\n", maxConsecutive);

    return 0;
}
