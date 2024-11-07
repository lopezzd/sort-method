#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		swap(&arr[minIndex], &arr[i]);
	}
}

void printArray(int arr[], int n) {
	if(n < 20) {
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
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
	selectionSort(arr, n);
	fim = clock();

	tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("Tempo de execução: %f segundos\n", tempo_cpu);


	printArray(arr, n);
	
	// Anotações
	
	/*
	Tamanho: 10
	Tempo: 0,000002 segundos
	
	Tamanho: 100
	Tempo: 0,000019 segundos
	
	Tamanho: 1000
	Tempo: 0,001153 segundos
	
	Tamanho: 10000
	Tempo: 0,116320 segundos
	
	Tamanho: 100000
	Tempo: 12,799901 segundos
	*/

	return 0;
}