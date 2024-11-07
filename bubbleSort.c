#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100000];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    srand(time(NULL));

    for (int i=0; i<n; i++)
    {
        arr[i] = rand();
    }

    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    bubbleSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    return 0;
}

