
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    printf("Enter the size of first array: ");
    scanf("%d", &m);

    int arr1[m];

    printf("Enter elements of first array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of second array: ");
    scanf("%d", &n);

    int arr2[n];

    printf("Enter elements of second array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (arr1[i] > arr1[j]) {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr2[i] > arr2[j]) {
                int temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    int i = 0, j = 0;
    long long minDiff = llabs((long long)arr1[0] - arr2[0]);

    while (i < m && j < n) {
        long long diff = llabs((long long)arr1[i] - arr2[j]);

        if (diff < minDiff) {
            minDiff = diff;
        }

        if (minDiff == 0) {
            break;
        }

        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    printf("Smallest difference: %lld\n", minDiff);

    return 0;
}