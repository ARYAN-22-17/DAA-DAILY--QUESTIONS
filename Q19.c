
#include <stdio.h>
#include <string.h>

int areAnagrams(char mainStr[], char pattern[]) {
    int n = strlen(mainStr);
    int m = strlen(pattern);

    if (m > n) {
        return 0;
    }

    int countMain[256] = {0};
    int countPattern[256] = {0};

    for (int i = 0; i < m; i++) {
        countMain[(unsigned char)mainStr[i]]++;
        countPattern[(unsigned char)pattern[i]]++;
    }

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < 256; j++) {
            if (countMain[j] != countPattern[j]) {
                break;
            }
        }

        if (j == 256) {
            return 1;
        }

        if (i < n - m) {
            countMain[(unsigned char)mainStr[i]]--;
            countMain[(unsigned char)mainStr[i + m]]++;
        }
    }

    return 0;
}

int main() {
    char mainStr[100005], pattern[100005];

    printf("Enter the main string: ");
    scanf("%100004s", mainStr);

    printf("Enter the pattern string: ");
    scanf("%100004s", pattern);

    if (areAnagrams(mainStr, pattern)) {
        printf("Anagram substring found.\n");
    } else {
        printf("No anagram substring found.\n");
    }

    return 0;
}
