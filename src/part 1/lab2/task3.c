#include <stdio.h>

int fact(int a) {
    int res = 1;
    for (int i = 1; i <= a; i++) {
        res *= i;
    }
    return res;
}

float pow(float num, int pow) {
    float res = 1;
    for (int i = 1; i <= pow; i++) {
        res *= num;
    }

    return res;
}

int main() {
    float X = 5;
    int N = 3;
    float res = 0;
    if (N <= 0) {
        printf("integer can't be less than 0");
    }

    for (int i = 0; i < N; i++) {
        printf("%d \n", i);
        printf("%d \n", N);
        res += (pow(-1, i) * pow(X, 2 * i + 1) / (fact(2 * i + 1)));
        printf("result - %f \n", res);

    }
    printf("result - %f", res);


    return 0;
}