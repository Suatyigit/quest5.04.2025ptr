#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM2 2
#define NUM3 3

int A[NUM2][NUM3];
int B[NUM3][NUM2];
int C[NUM2][NUM2];

void randomNumGenerator(int* ptr, int rows, int cols);
void printMatrix(int* ptr, int rows, int cols);
void multiplication();

int main() {
    srand(time(NULL));

    int* ptrA = &A[0][0];
    int* ptrB = &B[0][0];
    int* ptrC = &C[0][0];

    randomNumGenerator(ptrA, NUM2, NUM3);
    randomNumGenerator(ptrB, NUM3, NUM2);

    printf("A matrixi elemanlari :\n");
    printMatrix(ptrA, NUM2, NUM3);
    puts("");
    printf("B matrixi elemanlari :\n");
    printMatrix(ptrB, NUM3, NUM2);

    multiplication();
    printf("\nA(2x3) x B(3)(2) matrixlerinin carpma isleminin sonucu :\n");
    printMatrix(ptrC, NUM2, NUM2);
}

void randomNumGenerator(int* ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ptr[i * cols + j] = rand() % 10;   //A[i][j] = rand() % 10; gibi bir kod
        }
    }
}

void printMatrix(int* ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", ptr[i * cols + j]);
        }
        puts("");
    }
}

void multiplication() {
    for (size_t i = 0; i < NUM2; i++) {
        for (size_t j = 0; j < NUM2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < NUM3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
