#include <stdio.h>

float sqrt(int n) {
    for (float i = 1.0001; i <= n; i += 0.0001) {
        if (n - i * i <= 0.001) {

            return i;
        }
    }
}

char * place(int r, int a) {
    int diam = r * 2;
    int area = a * a;
    int diag = area * sqrt(2);
    if (diag < diam) {
        return "square can be placed in a circle \n";
    }
    if (diag > diam) {
        return "circle can be placed in a square \n";
    }
    if (diag == diam) {
        return "circle and square can be placed in each other \n";
    }
}
void main() {
    int a;
    int r;
    printf("input side of the square \n");
    scanf_s("%d", &a);
    printf("input radius \n");
    scanf_s("%d", &r);
    printf("%s", place(r, a));
}