#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int capacity;
  int size;
  int *data;
} IntArray;

void print_array(IntArray array) {
  for (int i = 0; i < array.size; i++) {
    printf("%d\t| %p\n", array.data[i], &array.data[i]);
  }
  printf("\n");
}


void pop_back(IntArray *array) { array->size -= 1; }

void push_back(IntArray *array, int new_element) {
  array->size += 1;
  if (array->size > array->capacity) {
	array->data = realloc(array->data, array->size);
	if (NULL == array->data) {
		exit(1);
	}
	// если size == capacity;
    array->data[array->size - 1] = new_element;
  }
}

int main(void) {
  IntArray arr = {0};
  printf("Enter the size: ");
  scanf("%d", &arr.size);
  arr.capacity = arr.size;

  arr.data = (int *)malloc(sizeof(int) * arr.capacity);
  if (arr.data == NULL) {
	return 1;
  }

  for (int i = 0; i < arr.size; i++) {
    printf("Enter the element[%d]: ", i);
    scanf("%d", &arr.data[i]);
  }

  print_array(arr);
  pop_back(&arr);
  print_array(arr);
  push_back(&arr, 21);
  print_array(arr);
  push_back(&arr, 42);
  print_array(arr);

  free(arr.data);
  return 0;
}