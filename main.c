#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password_utlis.h"

#define MASTER_PASS "admin123" 
#define KEY "mysecretkey"

void menu() {
    printf("\n===== PASSWORD MANAGER =====\n");
    printf("1. Add Credential\n");
    printf("2. View All Credentials\n");
    printf("3. Search Credential\n");
    printf("4. Delete Credential\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[100];
    printf("Enter Master Password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, MASTER_PASS) != 0) {
        printf("Incorrect password. Access denied.\n");
        return 1;
    }

    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) {
            Credential cred;
            printf("Website: ");
            fgets(cred.website, sizeof(cred.website), stdin);
            cred.website[strcspn(cred.website, "\n")] = 0;
            printf("Username: ");
            fgets(cred.username, sizeof(cred.username), stdin);
            cred.username[strcspn(cred.username, "\n")] = 0;
            printf("Password: ");
            fgets(cred.password, sizeof(cred.password), stdin);
            cred.password[strcspn(cred.password, "\n")] = 0;

            saveCredential(&cred, KEY);
        } else if (choice == 2) {
            viewCredentials(KEY);
        } else if (choice == 3) {
            char site[50];
            printf("Enter website to search: ");
            fgets(site, sizeof(site), stdin);
            site[strcspn(site, "\n")] = 0;
            searchCredential(site, KEY);
        } else if (choice == 4) {
            char site[50];
            printf("Enter website to delete: ");
            fgets(site, sizeof(site), stdin);
            site[strcspn(site, "\n")] = 0;
            deleteCredential(site, KEY);
        } else if (choice != 5) {
            printf("Invalid option.\n");
        }
    } while (choice != 5);

    return 0;
}
