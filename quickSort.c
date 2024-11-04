#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void quicksort(int *arr, int low, int high)
{
  int pivot, i, j, temp;
  if(low < high) {
    pivot = low;
    i = low;
    j = high;
    while(i < j) {

      while(arr[i] <= arr[pivot] && i <= high)
        i++;

      while(arr[j] > arr[pivot] && j >= low)
        j--;
        
      if(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
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
	quicksort(arr, 0, n-1);
	fim = clock();

	tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

	printf("Tempo de execução: %f segundos\n", tempo_cpu);

	printArray(arr, n);

	return 0;
}