
#ifndef LAB5_STRINGS_H
#define LAB5_STRINGS_H

#include "strings.h"
#include "stdlib.h"
#include "stdio.h"

int stringLength(const char *str, int start, int flag) {
    int length = 0;
    if (flag == 1) {
        while (str[start] != ' ' && str[start] != '\0' && str[start] != '\t') {
            start++;
            length++;
        }
    } else {
        while (str[start] != '\0') {
            start++;
            length++;
        }

    }
    return length;
}

char *printFrom(const char *str, int start) {
    char *resultStr = calloc(1, sizeof(char));
    int i = 1;
    while (str[start] != ' ' && str[start] != '\0' && str[start] !='\t') {
        resultStr = realloc(resultStr, sizeof(char) * i);
        resultStr[i - 1] = str[start];
        i++;
        start++;
    }

    return resultStr;
}

void findLongestWord(const char *str) {
    int i = 0;
    int lengthLongest = 0;
    int startOfWord = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
            continue;
        }
        if (stringLength(str, i, 1) > lengthLongest) {
            lengthLongest = stringLength(str, i, 1);
            startOfWord = i;
        }
        i += stringLength(str, i, 1);
    }
    printf("length of longest word - %d\n", lengthLongest);
    printf("Longest word is - %s", printFrom(str, startOfWord));

}

int strCompare(const char *str, const char *str2, int startFrom) {
    int i = 0;
    while(str2[i] == ' ' || str2[i] == '\0' || str2[i] == '\t'){
        i++;
    }
    while (str2[i] != ' ' && str2[i] != '\0' && str2[i] != '\t') {
        if (str[startFrom] == str2[i]) {
            i++;
            startFrom++;
        } else {
            return 0;
        }
    }
    return 1;
}

int findSimilarWord(const char *str, const char *str2) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\t') {
            i++;
            continue;
        }
        if (strCompare(str, str2, i)) {
            return i;
        }
        i += stringLength(str, i, 1);

    }
    return -1;
}

void deleteWord(char *str, int start) {
    int newLength = stringLength(str, 0, 2) - stringLength(str, start, 1) + 1;
    while (str[start] != ' ' && str[start] != '\0' && str[start] !='\t') {
        int i = start;
        while (str[i + 1] != '\0') {
            str[i] = str[i + 1];
            i++;
        }
        str[i] = '\0';

    }

    if (newLength != 1) {
        newLength -= 1;
        int i = start;
        while (str[i + 1] != '\0') {
            str[i] = str[i + 1];
            i++;
        }
    }
    str[newLength - 1] = '\0';
    str = realloc(str, newLength * sizeof(char));


}

int findLengthOfLowest(char* str){
    int lengthOfShortest = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
            continue;
        }
        if(lengthOfShortest == 0){
            lengthOfShortest = stringLength(str,i,1);
            i += stringLength(str,i,1);
            continue;
        }
        if (stringLength(str, i, 1) < lengthOfShortest) {
            lengthOfShortest = stringLength(str, i, 1);
        }
        i += stringLength(str, i, 1);
    }
    return lengthOfShortest;

}

void swapForString(char **arr, int first, int second) {
    char* tmp;
    tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

void HoareMethodForStrings(char** arr,int first,int last){
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(findLengthOfLowest(arr[i])<=findLengthOfLowest(arr[pivot])&&i<last)
                i++;
            while(findLengthOfLowest(arr[j])> findLengthOfLowest(arr[pivot]))
                j--;
            if(i<j){
                swapForString(arr,i,j);
            }
        }
        swapForString(arr,pivot,j);
        HoareMethodForStrings(arr,first,j-1);
        HoareMethodForStrings(arr,j+1,last);
    }
}

char** allocateStringArray(int argc, char** argv){
    char** arr = calloc((argc), sizeof(char*));
    for(int i = 0; i < argc; i++){
        arr[i] = calloc(stringLength(argv[i], 0, 2),sizeof(char));
        for(int j = 0; j < stringLength(argv[i], 0, 2); j++){
            arr[i][j] = argv[i][j];
            if(j == stringLength(argv[i], 0, 2) - 1){
                arr[i][j+1] = '\0';
            }
        }
    }
    return arr;
}

void printStringArray(int argc, char** arr){
    for(int i = 1; i < argc; i++){
        int strLen = stringLength(arr[i], 0, 2);
        printf("%s", arr[i]);
        for(int j = strLen; j < 25; j++){
            printf(" ");
        }
        printf("length of shortest word is %d\n", findLengthOfLowest(arr[i]));
    }
}


#endif //LAB5_STRINGS_H
