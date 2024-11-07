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
	if(n >= 20) return;

    for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	int arr[100000];
	int n = sizeof(arr) / sizeof(arr[0]);

	srand(time(NULL));

	for (int i=0; i<n; i++) {
		int num_aleatorio = (rand() % 10) + 1;
		arr[i] = num_aleatorio;
	}
	
	printArray(arr, n);

	clock_t inicio, fim;
	double tempo_cpu;

	inicio = clock();
	insertionSort(arr, n);
	fim = clock();

	tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("Tempo de execução: %f segundos\n", tempo_cpu);

	printArray(arr, n);

	// AnotaC'C5es

	/*
	Tamanho: 10
	Tempo: 0,000002 segundos

	Tamanho: 100
	Tempo: 0,000009 segundos

	Tamanho: 1000
	Tempo: 0,000733 segundos

	Tamanho: 10000
	Tempo: 0,060799 segundos

	Tamanho: 100000
	Tempo: 5,505111 segundos
	*/

	return 0;
}