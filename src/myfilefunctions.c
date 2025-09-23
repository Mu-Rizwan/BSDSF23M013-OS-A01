#include "../include/myfilefunctions.h"

#include <ctype.h>  // for isspace()

int wordCount(FILE* file, int* lines, int* words, int* characters) {
    if (file == NULL || lines == NULL || words == NULL || characters == NULL) {
        return -1; // invalid arguments
    }

    *lines = 0;
    *words = 0;
    *characters = 0;

    int c, inWord = 0;

    while ((c = fgetc(file)) != EOF) {
        (*characters)++;

        if (c == '\n') {
            (*lines)++;
        }

        if (isspace(c)) {
            inWord = 0;  // ended a word
        } else {
            if (inWord == 0) {
                (*words)++;  // new word begins
                inWord = 1;
            }
        }
    }

    // If file is not empty but doesn’t end with a newline, we still count last line
    if (*characters > 0 && c == EOF) {
        (*lines)++;
    }

    return 0;
}
#include "myfilefunctions.h"
#include <stdlib.h>
#include <string.h>

// Helper to duplicate a string safely
static char* my_strdup(const char* src) {
    char* dup = malloc(strlen(src) + 1);
    if (dup) {
        strcpy(dup, src);
    }
    return dup;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) {
        return -1; // invalid arguments
    }

    size_t capacity = 10;   // initial capacity for matches
    size_t count = 0;       // how many matches found
    char** results = malloc(capacity * sizeof(char*));
    if (!results) {
        return -1;
    }

    char buffer[1024]; // max line length (adjust if needed)
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str)) {
            if (count >= capacity) {
                capacity *= 2;
                char** temp = realloc(results, capacity * sizeof(char*));
                if (!temp) {
                    // free already allocated strings
                    for (size_t i = 0; i < count; i++) free(results[i]);
                    free(results);
                    return -1;
                }
                results = temp;
            }

            results[count] = my_strdup(buffer);
            if (!results[count]) {
                // free already allocated strings
                for (size_t i = 0; i < count; i++) free(results[i]);
                free(results);
                return -1;
            }
            count++;
        }
    }

    *matches = results;
    return (int)count;
}


