#include <stdio.h>
char * mutOpstNum(int a, int b, int c) {
    if((a != 0  && b != 0) || (b != 0 && c != 0) || (a != 0 && c != 0)){
        if (a == -b || a == -c || b == -c) {
            return  "True";
        }
    }
    return "False";

}
void main() {
    int a, b, c;
    printf("Input first num \n");
    scanf_s("%d", &a);
    printf("Input second num \n");
    scanf_s("%d", &b);
    printf("Input third num \n");
    scanf_s("%d", &c);
    printf("%s", mutOpstNum(a, b, c));

}
