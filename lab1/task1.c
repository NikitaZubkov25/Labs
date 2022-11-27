#include <stdio.h>

int pow(int num, int pow) {
    int result = 1;
    for (int i = 1; i <= pow; i++) {
        result *= num;
    }
    return result;
}
int geom (int b, int q, int n) {
    int sum = 0;
    if (q == 1) {
        sum = 0;
    }
    else
        sum = b * (pow(q,n) - 1) / (q - 1);
    return sum;



};
void main() {
    int b, q, n;
    scanf_s("%d", &b);
    scanf_s("%d", &q);
    scanf_s("%d", &n);
    int a = geom(b, q, n);
    printf("%i", a);
}