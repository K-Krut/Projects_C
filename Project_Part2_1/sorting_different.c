
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(a, b){int temp; temp=a; a=b; b=temp;}

void hoor_sort(int arr[], int left, int right);
void shell_sort(int arr[], int size);
void shuffle1_sort(int arr[], size_t size);
void print_arr(const int arr[], int size);
void bubble_sort(int arr[], int size);
void read_array(int arr[], int size);
void best_random_shuffle(int arr[], int size);

int main() {

  int size;
//  printf("Number of elements\n");
  scanf("%d", &size);
  fputc('\n', stdout);

  int arr[size];
//  printf("Elements:\n");
  read_array(arr, size);
  fputc('\n', stdout);

//  printf("Original:\n");
  print_arr(arr, size);

  bubble_sort(arr, size);
fputc('\n', stdout);
 // printf("Bubble sort:\n");
  print_arr(arr, size);
//  fputc('\n', stdout);

  shuffle1_sort(arr, size);
  printf("Shuffle sort 1:\n");
  print_arr(arr, size);
//  fputc('\n', stdout);

  hoor_sort(arr, 0, size - 1);
//  printf("Hoor sort:\n");
  print_arr(arr, size);
 // fputc('\n', stdout);
   printf("Shuffle sort 2:\n");
shuffle1_sort(arr, size);
// best_random_shuffle(arr, size);
//  printf("Shuffle sort:\n");
  print_arr(arr, size);
//  fputc('\n', stdout);

  shell_sort(arr, size);
//  printf("Shell sort:\n");
  print_arr(arr, size);

	return 0;
}

void read_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
}

void hoor_sort(int arr[], int left, int right){
	int i = left, j = right, step = -1, condition = 1;
	if (left >= right) return;
	do {
		if (condition == (arr[i] > arr[j])) {
			SWAP(arr[i], arr[j]);
			SWAP(i, j);
			step *= -1;
			condition = !condition;
		}
		j += step;
	} while (j != i);
	hoor_sort(arr, left, i - 1);
	hoor_sort(arr, i + 1, right);
}

void shell_sort(int arr[], int size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; ++i) {
			for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
				SWAP(arr[j], arr[j + gap]);
			}
		}
	}
}

void shuffle1_sort(int arr[], size_t size) {
	if (size > 1) {
		srand(time(NULL));
		for (size_t i = 0; i < size - 1; ++i) {
			size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
			SWAP(arr[j], arr[i]);
		}
	}
}


void print_arr(const int arr[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	fputc('\n', stdout);
}

void bubble_sort(int arr[], int size){
		for (int i = size - 2; i >= 1; i--) {
		for (int j = 0; j <= i; ++j) {
			if (arr[j] > arr[j + 1])
				SWAP(arr[j], arr[j + 1])
		}
	}
}
/*
void best_random_shuffle(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
		int temp=arr[i];
        arr[i]=arr[rand() % (size - i) + i];
		arr[rand() % (size - i) + i]=temp;
    }
}*/
