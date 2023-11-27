#include <stdio.h>
#include <stdlib.h>


#ifndef string_h
#define string_h


char* get_input(void) {
    char* input = (char*)malloc(0);
    int input_len = 1;
    int chr;
    
    while ((chr = getchar()) != '\n') {
        input = realloc(input, input_len++ * sizeof(char));
        input[input_len - 2] = chr;
    }
    
    
    return input;
}


void concatenate(char* str1, char str2, char** postfix) {
//    size_t len1 = strlen(str1);
//    size_t len2 = strlen(str2);
//
//    char *result = malloc(len1 + len2);
//
//    memcpy(result, str1, len1);
//    memcpy(result + len1, str2, len2);
//    
//    free(*postfix);
//    return result;
    
//    int len = (int)strlen(*postfix);
//    *postfix = realloc(*postfix, (len + 1) * sizeof(char));
//    *postfix[len] = str2;
}


int is_digit(char smbl) {
    if ('0' <= smbl && smbl <= '9')
        return 1;
    else if ('(' <= smbl && smbl <= '/' && smbl != '.' && smbl != ',')
        return 0;
    
    printf("syntax error\n");
    return -1;
}


int count(char* str, char chr) {
    int counter = 0;
    
    for (int i = 0; i < (int)strlen(str); i++)
        if (str[i] == chr)
            counter++;
    
    return counter;
}


#endif /* string_h */
