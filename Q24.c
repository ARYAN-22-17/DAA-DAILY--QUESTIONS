
#include <stdio.h>

int findPeakElement(int nums[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, i;

    printf("Enter array size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int peak = findPeakElement(nums, n);

    printf("Peak element index: %d\n", peak);
    printf("Peak element: %d\n", nums[peak]);

    return 0;
}