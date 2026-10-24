
#include <stdio.h>

int main() {
    int arr[] = {10, 12, 15, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int current = 1, longest = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            current++;
        } else {
            current = 1;
        }

        if (current > longest) {
            longest = current;
        }
    }

    printf("Longest increasing streak: %d\n", longest);

    return 0;
}