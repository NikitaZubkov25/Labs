#include <stdio.h>

float alg(int a) {
    float n = 1;
    float res = 1;
    for (n; res < a; n++) {
        res += 1 / n;
    }
    return n;
}
int main() {
    int a;
    scanf_s("%d", &a);
    printf("%f", alg(a));



    return 0;
}