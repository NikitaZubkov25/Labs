#include <stdio.h>
#include <stdlib.h>
#include "inp_out.h"
#include "strings.h"

void task1 (char* str){
    findLongestWord(str);
}


int main(){
    char* string;
    input_string(&string);
    printf("%s", string);
}