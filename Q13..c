
#include <stdio.h>
#include <limits.h>

double findMedian(int nums1[], int m, int nums2[], int n) {
    if (m > n) {
        return findMedian(nums2, n, nums1, m);
    }

    int low = 0, high = m;
    int half = (m + n + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = half - i;

        int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];

        int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 1) {
                return (left1 > left2) ? left1 : left2;
            }

            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return ((double)maxLeft + minRight) / 2.0;
        }
        else if (left1 > right2) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }

    return 0.0;
}

int main() {
    int m, n;

    printf("Enter size of first array: ");
    scanf("%d", &m);

    int nums1[m];

    printf("Enter sorted elements of first array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int nums2[n];

    printf("Enter sorted elements of second array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    if (m + n == 0) {
        printf("Median is undefined for two empty arrays.\n");
        return 0;
    }

    double median = findMedian(nums1, m, nums2, n);

    printf("Median: %.2f\n", median);

    return 0;
}
