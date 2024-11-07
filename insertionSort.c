#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
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
    insertionSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    return 0;
}