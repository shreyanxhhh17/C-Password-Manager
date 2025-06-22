#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "password_utlis.h"

#define FILENAME "data.enc"
#define MAX_CREDENTIALS 100

void encryptDecrypt(char *data, const char *key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % strlen(key)];
    }
}

void saveCredential(const Credential *cred, const char *key) {
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) {
        perror("Failed to open file");
        return;
    }
    Credential temp = *cred;
    encryptDecrypt((char *)&temp, key);
    fwrite(&temp, sizeof(Credential), 1, fp);
    fclose(fp);
}

void viewCredentials(const char *key) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No credentials saved yet.\n");
        return;
    }
    Credential cred;
    while (fread(&cred, sizeof(Credential), 1, fp)) {
        encryptDecrypt((char *)&cred, key);
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n",
            cred.website, cred.username, cred.password);
    }
    fclose(fp);
}

void searchCredential(const char *website, const char *key) {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No credentials found.\n");
        return;
    }
    Credential cred;
    int found = 0;
    while (fread(&cred, sizeof(Credential), 1, fp)) {
        encryptDecrypt((char *)&cred, key);
        if (strcmp(cred.website, website) == 0) {
            printf("Found:\nUsername: %s\nPassword: %s\n", cred.username, cred.password);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("No credentials found for %s\n", website);
    fclose(fp);
}

void deleteCredential(const char *website, const char *key) {
    FILE *fp = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.enc", "wb");
    if (!fp || !temp) {
        printf("Error deleting entry.\n");
        return;
    }
    Credential cred;
    int found = 0;
    while (fread(&cred, sizeof(Credential), 1, fp)) {
        encryptDecrypt((char *)&cred, key);
        if (strcmp(cred.website, website) != 0) {
            encryptDecrypt((char *)&cred, key); // re-encrypt
            fwrite(&cred, sizeof(Credential), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.enc", FILENAME);
    if (found)
        printf("Credential deleted.\n");
    else
        printf("Website not found.\n");
}
