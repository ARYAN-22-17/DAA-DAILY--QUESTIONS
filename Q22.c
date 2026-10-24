
#include <stdio.h>

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    int arr[n], temp[n];
    int j = 0;

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }

    while (j < n) {
        temp[j++] = 0;
    }

    printf("Array after shifting zeros: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    printf("\n");
    return 0;
}
