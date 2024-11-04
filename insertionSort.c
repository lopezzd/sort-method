#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Função de ordenação Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // O elemento a ser inserido
        int j = i - 1;

        // Move os elementos do arr[0..i-1], que são maiores que a chave,
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insere a chave na posição correta
    }
}

// Função para imprimir o array
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