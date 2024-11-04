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
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[10];
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

	printf("Tempo de execuC'C#o: %f segundos\n", tempo_cpu);

	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}