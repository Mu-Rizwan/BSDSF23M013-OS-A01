#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"
int main() {

	printf("--- Testing String Functions ---\n");
	// Add code here to test each of your string functions.
	
	char str1[] = "Hello";
	char str2[50];
	char str3[50] = "World";
    	char str4[50] = "Hi, ";

    	printf("Testing mystrlen:\n");
    	printf("Length of \"%s\" = %d\n\n", str1, mystrlen(str1));

    	printf("Testing mystrcpy:\n");
    	mystrcpy(str2, str1);
    	printf("Copied string: \"%s\"\n\n", str2);

    	printf("Testing mystrncpy:\n");
    	mystrncpy(str2, str3, 3);
    	printf("Copied first 3 chars from \"%s\": \"%s\"\n\n", str3, str2);

    	printf("Testing mystrcat:\n");
    	mystrcat(str4, str3);
    	printf("Concatenation result: \"%s\"\n\n", str4);

 	printf("\n--- Testing File Functions ---\n");
 	// Add code here to test your file functions.
	
	FILE* f = fopen("src/sample.txt", "r");
	
    	if (!f) {
        	perror("Failed to open sample.txt");
        	return 1;
    	}

    	// ---- Test wordCount ----
    	int lines, words, chars;
    	if (wordCount(f, &lines, &words, &chars) == 0) {
        	printf("wordCount() results:\n");
        	printf("Lines: %d\n", lines);
        	printf("Words: %d\n", words);
        	printf("Characters: %d\n\n", chars);
    	} else {
        	printf("wordCount() failed.\n");
    	}

    	// Reset file pointer for next function
    	rewind(f);

    	// ---- Test mygrep ----
    	char** matches;
    	const char* search = "hello";
    	int count = mygrep(f, search, &matches);

    	if (count >= 0) {
        	printf("mygrep() results for search string \"%s\":\n", search);
        	printf("Found %d matching lines:\n", count);
        	for (int i = 0; i < count; i++) {
        		printf("%s", matches[i]); // line already has newline if present
            		free(matches[i]);         // free each line
        	}
        	free(matches); // free the array
        	printf("\n");
    	} else {
        	printf("mygrep() failed.\n");
    	}

    	fclose(f);
    	
 	return 0;
}
