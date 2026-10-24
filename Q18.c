
#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        printf("Number of unique elements: 0\n");
        return 0;
    }

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
