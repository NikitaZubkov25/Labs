#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proverka_vvoda(int* adr)
{
    int num = 0;
    while (!scanf_s("%d", &num) || getchar() != '\n' || num <= 0)
    {
        printf("\nError! Try again: ");
        rewind(stdin);
    }
    *adr = num;
}

void memory(int** arr, int size)
{
    *arr = malloc(size * sizeof(int));
}

void memory_two(int*** arr, int rows, int cols)
{
    *arr = calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; ++i)
        (*arr)[i] = calloc(cols, sizeof(int));
}

void arrayPrint(int* arr, int size)
{
    for (int i = 0; i < size; ++i) printf("%5d", arr[i]);
    printf("\n");
}

void matrixPrint(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void matrixWavePrint(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != -100)printf("%5d ", matrix[i][j]);
            else {
                printf(" -100");
                break;
            }
        }
        printf("\n");
    }
}

void arrayInput(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("Enter %d element: ", i + 1);
        while (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n')
        {
            printf("Error!\n");
            rewind(stdin);
        }
    }
}

void matrixInput(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = rand() % 201 - 100;
        }
    }
}

void matrixWaveInput(int** matrix, int rows, int cols)
{
    int end;
    for (int i = 0; i < rows; ++i)
    {
        end = rand() % (cols - 1) + 2;
        for (int j = 0; j < end; ++j)
        {
            int num = rand() % 201 - 100;
            matrix[i][j] = num;
        }
        if (end == cols) {
            matrix[i][cols - 1] = -100;
        }
        else {
            matrix[i][end] = -100;
        }
    }
}

void delete_K_Elements(int** arr, int* size, int k)
{
    int dif = 0;
    for (int i = 0; i < *size; ++i)
    {
        if (!((i + 1) % k))
        {
            ++dif;
            continue;
        }
        (*arr)[i - dif] = (*arr)[i];
    }
    *size -= *size / k;
    *arr = realloc(*arr, (*size) * sizeof(int));
}

void delete_K_Rows(int*** arr, int* rows, int k)
{
    for (int i = *rows - 1; i >= 0; i--)
    {
        if (!((i + 1) % k))
        {
            for (int j = i; j < *rows - 1; j++)
            {
                *(*arr + j) = *(*arr + j + 1);
            }
            (*rows)--;
        }
    }
    (** arr) = realloc(**arr, (*rows) * sizeof(int*));
}

void delete_Diagonal(int*** arr, int rows, int* cols)
{
    for (int i = 0; i < (*cols >= rows ? rows : *cols); ++i)
    {
        for (int j = i; j < *cols - 1; ++j)
        {
            (*arr)[i][j] = (*arr)[i][j + 1];
        }
    }
    *cols -= 1;
    for (int i = 0; i < rows; ++i)
    {
        (*arr)[i] = realloc((*arr)[i], (*cols) * sizeof(int));
    }
}

void free_memory(int* arr)
{
    free(arr);
}

void free_memory_matrix(int** arr, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(*(arr + i));
    }
    free(arr);
}

int main() {
    srand(time(NULL));

        int choice;
        int* arr, size, k;
        int** matx, rows, cols;
        printf("Task 1, 2, 3: ");
        while (scanf_s("%d", &choice) != 1 || getchar() != '\n' || choice < 0 || choice > 3)
        {
            printf("Error!\n");
            rewind(stdin);
        }
        system("cls");
        switch (choice) {

        case 1:
            printf("Size: ");
            proverka_vvoda(&size);
            memory(&arr, size);
            arrayInput(arr, size);
            printf("Array:\n");
            arrayPrint(arr, size);
            printf("Delete k element: ");
            proverka_vvoda(&k);
            delete_K_Elements(&arr, &size, k);
            printf("New array:\n");
            arrayPrint(arr, size);
            free_memory(arr);
            break;
        case 2:
            printf("Rows: ");
            proverka_vvoda(&rows);
            printf("Cols: ");
            proverka_vvoda(&cols);
            memory_two(&matx, rows, cols);
            printf("Array:\n");
            matrixWaveInput(matx, rows, cols);
            matrixWavePrint(matx, rows, cols);
            printf("Enter k: ");
            proverka_vvoda(&k);
            delete_K_Rows(&matx, &rows, k);
            printf("New Array:\n");
            matrixWavePrint(matx, rows, cols);
            free_memory_matrix(matx, rows);
            break;
        case 3:
            printf("Rows: ");
            proverka_vvoda(&rows);
            printf("Cols: ");
            proverka_vvoda(&cols);
            memory_two(&matx, rows, cols);
            matrixInput(matx, rows, cols);
            printf("Array:\n");
            matrixPrint(matx, rows, cols);
            delete_Diagonal(&matx, rows, &cols);
            printf("New array:\n");
            matrixPrint(matx, rows, cols);
            free_memory_matrix(matx, rows);
            break;
        }
}