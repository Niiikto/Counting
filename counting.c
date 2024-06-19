#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//void counting(char * word, int SIZE);
void get_word(char lines[], int maxlen) {
    printf("Please enter your words: ");
    char *result;
    int current_len = 0;

    while ((result = fgets(lines + current_len, maxlen - current_len, stdin)) != NULL) {
        current_len += strlen(lines + current_len);
        if (current_len >= maxlen - 1) break;
    }

    if (ferror(stdin)) {
        perror("failed to read input");
        exit(1);
    }

    return;
}

int main(void) {
    const unsigned int THE_SIZE = 50000;
    char theword[THE_SIZE];
    unsigned long charCount = 0;

    get_word(theword, THE_SIZE);

    for (int i = 0; theword[i] != '\0'; i++) {
        if (!isspace(theword[i])) {
            charCount += 1;
        }
    }

    

    unsigned long wordCount = 0;

    for(int i = 0; theword[i] != '\0'; i++){
        while (isspace(theword[i]) && theword[i] != '\0') {
            i++;
        }
        if (theword[i] != '\0' && !isspace(theword[i])) {
            wordCount++;
        }
        while (theword[i] != '\0' && !isspace(theword[i])) {
            i++;
        }
    }
    


    unsigned long lineCount = 0;

    for(int i = 0; theword[i] != '\0'; i++){
        if(theword[i] != '\n'){
            lineCount++;
        }
        while (theword[i] != '\n') {
            i++;
        }
    }
    

    unsigned long spaceCount = 0;

    for (int i = 0; theword[i] != '\0'; i++) {
        if (isspace(theword[i])) {
            spaceCount += 1;
        }
    }

    

    printf("Characters: %lu", charCount);
    printf("Words: %lu", wordCount);
    printf("Lines: %lu", lineCount);
    printf("Spaces: %lu", spaceCount);


    return 0;
}
