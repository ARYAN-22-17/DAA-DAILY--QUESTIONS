
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    float bucket[n][n];
    int count[n];

    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Place elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);

        if (index >= n)
            index = n - 1;

        bucket[index][count[index]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    // Combine all buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements (1 to 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid number of elements.\\n");
        return 1;
    }

    float arr[n];

    printf("Enter %d numbers between 0 and 1:\\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);

        if (arr[i] < 0 || arr[i] > 1) {
            printf("Please enter values between 0 and 1 only.\\n");
            return 1;
        }
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    printf("\\n");
    return 0;
}
