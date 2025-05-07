#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int capacity;  // вместимость
  int size;      // размер
  int *data;     // массив
} IntArray;

void print_array(IntArray array) {
  for (int i = 0; i < array.size; i++) {
    printf("%d\t| %p\n", array.data[i], &array.data[i]);
  }
  //   printf("\n");
}

// Функцуия для выделения памяти и иницилизации массива
void init_array(IntArray *p_array, int size_function_init_array) {
  p_array->capacity = size_function_init_array;
  p_array->size = size_function_init_array;
  p_array->data = (int *)malloc(sizeof(int) * size_function_init_array);
  if (p_array->data == NULL) {
    fprintf(stderr, "Ошибка выделения памяти\n");
    exit(1);
  }
}

// Function to remove the last element from the array
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

void reserve_array(IntArray *p_array) {
  for (int i = 0; i < p_array->size / 2; i++) {
    int temp = p_array->data[i];
    p_array->data[i] = p_array->data[p_array->size - 1 -i];
    p_array->data[p_array->size - 1 - i] = temp;
  }
}

// Функция для получения колическтва заполненных элементов
int get_size(IntArray *p_array) { return p_array->size; }

// Функция для получения максимальной емкости массива
int get_capacity(IntArray *p_array) { return p_array->capacity; }

int main(void) {
  IntArray arr = {0};
  init_array(&arr, 5);

  for (int i = 0; i < arr.size; i++) {
    printf("Enter the element[%d]: ", i);
    scanf("%d", &arr.data[i]);
  }

  print_array(arr);
  printf("Current size: %d\n", get_size(&arr));
  printf("Current capacity: %d\n\n", get_capacity(&arr));

  reserve_array(&arr);
  printf("Reversing the array....\n");
  print_array(arr);
  printf("\n");

  pop_back(&arr);
  print_array(arr);
  printf("Current size after pop_back: %d\n", get_size(&arr));
  printf("Current capacity: %d\n", get_capacity(&arr));
  //   push_back(&arr, 21);
  //   print_array(arr);
  //   push_back(&arr, 42);
  //   print_array(arr);

  free(arr.data);
  return 0;
}