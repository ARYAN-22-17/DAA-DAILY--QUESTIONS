
#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], result[n];

    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[left] * arr[left] > arr[right] * arr[right]) {
            result[i] = arr[left] * arr[left];
            left++;
        } else {
            result[i] = arr[right] * arr[right];
            right--;
        }
    }

    printf("Sorted squares: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
    return 0;
}