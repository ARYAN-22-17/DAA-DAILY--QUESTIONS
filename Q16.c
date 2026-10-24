
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    char s[100005];

    scanf("%d", &t);

    while (t--) {
        scanf("%100004s", s);

        int n = strlen(s);
        int lower = 0, upper = 0;
        int digit = 0, special = 0;

        for (int i = 0; i < n; i++) {
            if (islower((unsigned char)s[i])) {
                lower = 1;
            }

            if (i > 0 && i < n - 1) {
                if (isupper((unsigned char)s[i])) {
                    upper = 1;
                }

                if (isdigit((unsigned char)s[i])) {
                    digit = 1;
                }

                if (s[i] == '@' || s[i] == '#' ||
                    s[i] == '%' || s[i] == '&' ||
                    s[i] == '?') {
                    special = 1;
                }
            }
        }

        if (lower && upper && digit && special && n >= 10) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
