#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Структура теста
int main() {
  int rows = 3;
  int columns = 4;
  // Создание матрицы (malloc)
  matrix_t A = {NULL, 0, 0};

  A.rows = rows;
  A.columns = columns;
  A.matrix = (double **)malloc(A.rows * sizeof(double *));
  if (A.matrix != NULL) {
    for (int i = 0; i < A.rows; i++) {
      A.matrix[i] = (double *)malloc(A.columns * sizeof(double));
      if (A.matrix[i] == NULL) {
        for (int j = 0; j < i; j++) {
          free(A.matrix[j]);
        }
        free(A.matrix);
        A.matrix = NULL;
        A.rows = 0;
        A.columns = 0;
        return 1;  // статус ошибки
      }
    }
  }

  // Инициализация элементов матрицы
  double k = 0.0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = ++k;
    }
  }

  // Действие
  // Печать матрицы
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%3.0lf ", A.matrix[i][j]);
    }
    printf("\n");
  }

  // Сравнение с эталонным

  // Освобождение памяти (free)
  for (int i = 0; i < A.rows; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
  A.matrix = NULL;
  A.rows = 0;
  A.columns = 0;

  return 0;
}
