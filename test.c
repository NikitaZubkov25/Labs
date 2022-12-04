#include <arrays.h>
void delete_element(int* arr, int* len, int k) {
    for(int i = *len - 1; i >= 0; i--){
        if((i+1) % k == 0){
            for(int j = i; j < *len; j++){
                arr[j] = arr[j + 1];
            }
            (*len)--;
        }
    }
}

int main(){
    int len = 5;
    int* arr = malloc(sizeof(int) * len);
    fill_array(arr, len);
    delete_element(arr,&len,2);
    realloc(arr,len * sizeof(int));
    print_array(arr,len);
    return 0;
}