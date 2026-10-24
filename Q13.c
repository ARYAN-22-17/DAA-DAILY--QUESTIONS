
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of bars: ");
    scanf("%d", &n);

    int height[n];

    printf("Enter the heights of the bars: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    printf("Total trapped rainwater: %d\n", water);

    return 0;
}
