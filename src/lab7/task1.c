//
// Created by Katerina on 01.12.2022.
//
#include <stdio.h>
#include <stdlib.h>


int strcmpare(char* str, char* str2){
    int i = 0;
    while(str[i] != '\0' && str2[i]){
        if(str[i] != str2[i]){
            printf("not similar");
            return 0;
        }
        i++;
    }
    printf("similar");
    return 0;
}


int input_string(char* str){
    char c;
    int size = 1;
    while((c = getchar()) != '\n'){
        if((c >= 'a' && c <= 'z') || (c>='A' && c <= 'Z') || c == ' '){
            str = realloc(str, size * 1);
            str[size - 1] = c;
            size++;
            continue;
        } else{
            str = (char*)realloc(str, 1);
            rewind(stdin);
            return 0;
        }
    }
    str[size-1] = '\n';
    return 1;
};

void get_string(char *str){
    while(input_string(str) == 0){
        printf("Try again");
    }
}

int main(){
    char* string = calloc(1,1);
    char* string2 = calloc(1,1);

    get_string(string);
    get_string(string2);
    strcmpare(string,string2);
}