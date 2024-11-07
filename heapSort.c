#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void heapify(int arr[], int n, int i) {

    int largest = i; 

    int l = 2 * i + 1; 

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {

        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
	heapSort(arr, n);
	fim = clock();

	tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("Tempo de execução: %f segundos\n", tempo_cpu);

	printArray(arr, n);

	// AnotaC'C5es

	/*
	Tamanho: 10
	Tempo: 0,000002 segundos

	Tamanho: 100
	Tempo: 0,000012 segundos

	Tamanho: 1000
	Tempo: 0,000152 segundos

	Tamanho: 10000
	Tempo: 0,001727 segundos

	Tamanho: 100000
	Tempo: 0,019775 segundos
	*/

	return 0;
}