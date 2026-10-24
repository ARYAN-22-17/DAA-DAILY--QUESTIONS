
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    char correctPassword[] = "12345";

    while (1) {
        printf("Enter password: ");
        scanf("%49s", password);

        if (strcmp(password, correctPassword) == 0) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
        }
    }

    return 0;
}
