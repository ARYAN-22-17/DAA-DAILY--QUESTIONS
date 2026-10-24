
#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];

    printf("Enter a string: ");
    scanf("%100004s", s);

    int n = strlen(s);
    int last[256];

    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0, maxLength = 0, start = 0;

    for (int right = 0; right < n; right++) {
        unsigned char ch = (unsigned char)s[right];

        if (last[ch] >= left) {
            left = last[ch] + 1;
        }

        last[ch] = right;

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }
    }

    printf("Longest substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", s[i]);
    }

    printf("\nLength: %d\n", maxLength);

    return 0;
}
