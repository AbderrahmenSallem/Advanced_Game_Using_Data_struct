#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to find the position of a character in a string
int pos(char line[], char x) {
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == x) {
            return i;
        }
    }
    return -1;
}

// Function to extract a substring from a string
void substr(char string[], int x, int y) {
    int i;
    if (y != -1) {
        char ch[y - x + 1];
        for (i = x; i < y; i++) {
            ch[i - x] = string[i];
        }
        ch[y - x] = '\0';
        strcpy(sub, ch);
    } else {
        int n = strlen(string);
        char ch[n - x + 1];
        for (i = x; i < n; i++) {
            ch[i - x] = string[i];
        }
        ch[n - x] = '\0';
        strcpy(sub, ch);
    }
}

// Function to generate a custom hash value for a string
int customHash(const char *str) {
    unsigned int hash = 0;
    int c;
    int position = 1; // Starting position, assuming positions start at 1

    while ((c = *str++)) {
        hash += (c * position); // Multiply ASCII value by position
        position++;
    }

    return hash;
}
