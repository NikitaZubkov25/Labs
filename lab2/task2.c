#include <stdio.h>

int main() {
    int n;
    int prod = 1;
    int sum = 0;
    scanf_s("%d", &n);
    for (int i = 0; i <= n; i += 3) {
        sum += i;
        if(i > 0){
            prod *= i;
        }
    }
    printf("sum:%d \n", sum);
    printf("prod:%d", prod);
    return 0;
}
