#ifndef PASSWORD_UTILS_H
#define PASSWORD_UTILS_H

typedef struct{
    char website[50];
    char username[50];
    char password[50];
}Credential;


void encryptDecrypt(char *data, const char *key);
void saveCredential(const Credential *cred, const char *key);
void viewCredentials(const char *key);
void searchCredential(const char *website, const char *key);
void deleteCredential(const char *website, const char *key);
#endif