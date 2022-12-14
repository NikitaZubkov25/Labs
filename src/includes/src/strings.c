
#ifndef LAB5_STRINGS_H
#define LAB5_STRINGS_H

#include "strings.h"
#include "stdlib.h"
#include "stdio.h"

int stringLength(const char *str, int start, int flag) {
    int length = 0;
    if (flag == 1) {
        while (str[start] != ' ' && str[start] != '\0') {
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
    while (str[start] != ' ' && str[start] != '\0') {
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
        if (str[i] == ' ') {
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
    while (str2[i] != ' ' && str2[i] != '\0') {
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
        if (str[i] == ' ' || str[i] == '\0') {
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
    while (str[start] != ' ' && str[start] != '\0') {
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

#endif //LAB5_STRINGS_H
