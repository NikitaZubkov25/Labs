
#ifndef LAB5_STRINGS_H
#define LAB5_STRINGS_H

#include "inp_out.h"

int stringLength(const char* str, int start){
    int length = 0;
    while(str[start] != ' ' && str[start] != '\0'){
        start++;
        length++;
    }
    return length;
}

char* printFrom(const char* str, int start){
    char* resultStr = calloc(1,sizeof(char));
    int i = 1;
    while(str[start] != ' ' && str[start] != '\0'){
        resultStr = realloc(resultStr, sizeof(char) * i);
        resultStr[i] = str[start];
        i++;
        start++;
    }

    return resultStr;
}

void findLongestWord(char *str) {
    int i = 0;
    int lengthLongest = 0;
    int startOfWord = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            i++;
            continue;
        }
        if(stringLength(str,i) > lengthLongest){
            lengthLongest = stringLength(str,i);
            startOfWord = i;
        }
        i+= stringLength(str,i);
    }
    printf("length of longest word - %d\n", lengthLongest);
    printf( "Longest word is - %s", printFrom(str,startOfWord));

}

#endif //LAB5_STRINGS_H
