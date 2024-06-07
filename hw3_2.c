#include <stdio.h>

#define MAX_SIZE 10
void quick_sort(double arr[], int low,  int high,int (*comp)(void *, void *)) {
	int i, last;
	void swap(void *v[], int, int);


	if (low < high) {
		double pivot = arr[high]; // 배열의 마지막 요소 선택
		int i = low -1; // 요소들 중 마지막 인덱스

		for (int j = low; j<=high-1; j++) {
			if(arr[j] < pivot) {
				i++;
				double temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		double temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;


		quick_sort(arr, low, i);
                quick_sort(arr, i + 2, high);
	}
}

void print_array(double arr[], int size) {
	for(int i = 0; i < size; i++)
		printf("%.1f ", arr[i]);
	printf("\n");
}
int main(void) {
	double array[MAX_SIZE] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};
	int size = MAX_SIZE;

	print_array(array, size);

	quick_sort(array, 0, size );

	printf("\n");
	print_array(array, size);

	return 0;
}
