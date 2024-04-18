#include <stdio.h>

#define MAX_SIZE 10

void quick_sort(double arr[], int left, int right);
int partition(double arr[], int left, int right);
void swap(double *a, double *b);
void print_array(double arr[], int size);

int main() {
	double array[MAX_SIZE] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};
	int size = MAX_SIZE;

	print_array(array, size);

	quick_sort(array, 0, size -1);

	printf("\n");
	print_array(array, size);

	return 0;
}

void quick_sort(double arr[], int left, int right) {
	if (left < right) {
		int pivot_index = partition(arr, left, right);
		quick_sort(arr, left, pivot_index -1);
		quick_sort(arr, pivot_index +1, right);
	}
}

int partition(double arr[], int left, int right) {
	double pivot = arr[right];
	int i = left -1;

	for (int j = left; j < right; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[right]);
	return i+1;
}

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;

}

void print_array(double arr[], int size) {
	for (int i = 0; i <size; i++) {
		printf("%.1f ", arr[i]);
	}
}
