#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "inp_out.h"

void task1(char *str) {
    findLongestWord(str);
}

void task2(char* str, char* str2){
    deleteWord(str, findSimilarWord(str, str2));
}


int main() {
    char *string;
    char *string2;
    while (1) {

        input_string(&string);
        input_string(&string2);
        task2(string, string2);
        printf("%s\n", string);

    }
//    void (*funcPointer)(char*) = task1;
//    funcPointer(string);
    free(string);
}