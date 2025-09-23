#include "../include/mystrfunctions.h"

int mystrlen(const char* s){
	int len =0;
	for(int i = 0; s[i] != '\0'; i++){
		len++;
	}
	return len;
}

int mystrcpy(char* dest, const char* src){
	
	int i = 0;
	for(; src[i] != '\0'; i++){
		dest[i] = src[i];
	}
	
	dest[i] = '\0';
	return 1;
}

int mystrncpy(char* dest, const char* src, int n){
	
	int i = 0;
	for(; i < n && src[i] != '\0'; i++){
		dest[i] = src[i];
	}
	
	dest[i] = '\0';
	return 1;
}

int mystrcat(char* dest, const char* src) {
    
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return 1;
}

