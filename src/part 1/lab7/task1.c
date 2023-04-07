#include <stdio.h>
#include "strings.h"
#include "inp_out.h"

void FindLongest(char *str) {
    findLongestWord(str);
}

void DeleteWord(char *str, char *str2) {
    if (findSimilarWord(str, str2) == -1) {
        printf("There is now Similar word\n\n\n");
        return;
    } else {
        deleteWord(str, findSimilarWord(str, str2));
    }
}


int main() {
    char *string;
    char *string2;
    void (*task1)(char *) = FindLongest;
    void (*task2)(char *, char *) = DeleteWord;
    while (1) {
        int choice = 0;
        input(&choice, 0,2, "1.Find longest word in string\n2.Delete word that similar to first word in second string\n0.Exit\nYour choice:");
        if(choice == 1){
            printf("\n\nEnter string:");
            input_string(&string);
            printf("%s\n", string);
            task1(string);
            printf("\n\n");
            continue;
        }
        if(choice == 2){
            printf("\n\nEnter string(S):");
            input_string(&string);
            printf("Enter string(S0):");
            input_string(&string2);
            printf("S - %s\nS0 - %s\n", string, string2);
            task2(string,string2);
            printf("Result - %s\n\n\n", string);
            continue;
        }
        if(choice == 0){
            break;
        }
    }
}