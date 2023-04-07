#include "lab3.h"
#include "helpers.h"



int main() {
    int len = 0;
    TVSeries *arr = malloc(1 * sizeof(TVSeries));
    initialSeries(&arr, &len);
    menu(&arr,&len);

    return 0;
}