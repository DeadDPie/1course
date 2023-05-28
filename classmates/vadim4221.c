//
// Created by user on 08.03.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <minmax.h>

typedef struct {
    unsigned rows;
    unsigned cols;
    double** elems;
} Matrix;

FILE* checked_fopen(const char* filename, const char* mode) {
    FILE* f = fopen(filename, mode);
    if (!f) {
        fprintf(stderr, "fopen(%s, %s) failed (errno=%d)", filename, mode, errno);
        exit(1);
    }
    return f;
}

void* checked_malloc(unsigned size) {
    void* p = malloc(size);
    if (!p) {
        fprintf(stderr, "malloc(%u) failed", size);
        exit(1);
    }
    return p;
}

void* checked_calloc(unsigned count, unsigned size) {
    void* p = calloc(count, size);
    if (!p) {
        fprintf(stderr, "calloc(%u, %u) failed", count, size);
        exit(1);
    }
    return p;
}

void check(int cond, const char* msg) {
    if (!cond) {
        fprintf(stderr, "%s", msg);
        exit(1);
    }
}

Matrix* matrix_alloc(unsigned rows, unsigned cols) {
    check(cols > 0 && rows > 0, "invalid rows or cols argument");
    Matrix* matrix = checked_malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->elems = checked_calloc(rows, sizeof(Matrix*));
    for (size_t i = 0; i < rows; i++) matrix->elems[i] = checked_calloc(cols, sizeof(double));
    return matrix;
}

void matrix_free(Matrix* matrix) {
    for (size_t i = 0; i < matrix->rows; i++) free(matrix->elems[i]);
    free(matrix);
}

void matrix_printf(Matrix* matrix, FILE* out) {
    fprintf(out, "size=%ux%u\n", matrix->rows, matrix->cols);
    for (unsigned row = 0; row < matrix->rows; row++) {
        for (unsigned col = 0; col < matrix->cols; col++) {
            fprintf(out, "%4.1lf%s", matrix->elems[row][col], col == matrix->cols - 1 ? "\n" : " ");
        }
    }
}

Matrix* matrix_scanf(FILE* in) {
    unsigned rows, cols;
    check(fscanf(in, "%u %u", &rows, &cols) == 2, "fscanf rows and cols fail");
    Matrix* matrix = matrix_alloc(rows, cols);
    for (unsigned row = 0; row < matrix->rows; row++) {
        for (unsigned col = 0; col < matrix->cols; col++) {
            check(fscanf(in, "%lf", &matrix->elems[row][col]) == 1, "fscanf element fail");
        }
    }
    return matrix;
}

Matrix* matrix_reduce(Matrix* source, unsigned xrow, unsigned xcol) {
    check(source->cols > 1 && source->rows > 1, "source matrix is too small");
    check(xrow < source->rows && xcol < source->cols, "invalid xrow or xcol argument");
    Matrix* result = matrix_alloc(source->rows - 1, source->cols - 1);
    for (unsigned row = 0; row < result->rows; row++)
        for (unsigned col = 0; col < result->cols; col++)
            result->elems[row][col] = source->elems[row + (row >= xrow ? 1 : 0)][col + (col >= xcol ? 1 : 0)];
    return result;
}

double matrix_det(Matrix* matrix) {
    check(matrix->rows == matrix->cols, "matrix is not square");
    unsigned n = matrix->rows;
    if (n == 1) return matrix->elems[0][0];
    double det = 0;
    for (int col = 0; col < n; col++) {
        Matrix* tmp = matrix_reduce(matrix, 0, col);
        det += pow(-1, col) * matrix->elems[0][col] * matrix_det(tmp);
        matrix_free(tmp);
    }
    return det;
}

unsigned matrix_rank(Matrix* matrix) {
    unsigned result = 0;
    unsigned minor_rank = 1;
    unsigned rows = matrix->rows;
    unsigned cols = matrix->cols;
    unsigned max_minor_rank = min(rows, cols);
    while (minor_rank <= max_minor_rank) {
        Matrix* tmp = matrix_alloc(minor_rank, minor_rank);
        for (int r1 = 0; r1 < (rows - (minor_rank - 1)); r1++) {
            for (int c1 = 0; c1 < (cols - (minor_rank - 1)); c1++) {
                for (int r2 = 0; r2 < minor_rank; r2++) {
                    for (int c2 = 0; c2 < minor_rank; c2++) {
                        tmp->elems[r2][c2] = matrix->elems[r1 + r2][c1 + c2];
                    }
                }
                if (matrix_det(tmp) != 0) {
                    result = minor_rank;
                    break; // found non-zero determinant, exit for
                }
            }
            if (result == minor_rank) break; // already found, exit for
        }
        matrix_free(tmp);
        minor_rank++;
    }
    return result;
}

void test(const char* filename) {
    printf("filename=%s\n", filename);

    FILE* f = checked_fopen(filename, "r");

    unsigned test_count;
    check(1 == fscanf(f, "%u", &test_count), "can not read test_count");

    for (int i=0; i<test_count; i++) {
        Matrix* m = matrix_scanf(f);
        unsigned expected_rank;
        check(1 == fscanf(f, "%u", &expected_rank), "can not read expected_rank");
        matrix_printf(m, stdout);
        unsigned calculated_rank = matrix_rank(m);
        printf("calculated rank=%u\nexpected rank=%u\n\n", calculated_rank, expected_rank);
        check(calculated_rank == expected_rank, "ranks do not match");
        matrix_free(m);
    }
    fclose(f);
}

int main() {
    test("test.txt");
    return 0;
}

// Формат входного файла:
//
// Первое число - количество тестовых матриц
//
// Для каждой матрицы:
// Первая пара чисел - размерность матрицы (количество строк и столбцов)
// Далее - элементы матрицы
// Сразу после элементов матрицы - ожидаемый ранг матрицы (для проверки)
