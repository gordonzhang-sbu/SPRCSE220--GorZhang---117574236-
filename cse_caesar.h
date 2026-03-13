#ifndef CSE_CAESAR_H
#define CSE_CAESAR_H

int encryptCaesar(const char *plaintext, char *ciphertext, int key);
int decryptCaesar(const char *ciphertext, char *plaintext, int key);
int hasEOM(const char *string, int index);

#endif
