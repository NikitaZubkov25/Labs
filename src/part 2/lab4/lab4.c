#include "lab4.h"


int main (){
    int len = 0;
    TVSeries* arr = malloc(sizeof(TVSeries));
    initialSeries(&arr, &len);
    menu(&arr, &len);

    return 0;
}