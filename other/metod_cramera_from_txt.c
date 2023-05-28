#include <stdio.h>
#include <stdlib.h>

void metod_cramera_from_txt(FILE *file){


    int i, j;
    int **matrix;
    matrix =(int**)malloc(sizeof(int*)*4); //make matrix
    for(i = 0; i < 4; i++)
        matrix[i] = (int*)malloc(sizeof(int)*4);
    //read digits to matrix
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            fscanf(file,"%d",&matrix[i][j]);
        }
    }
    printf("\nМатрица коэфициентов: \n");
// печать элементов матрицы
    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++)
            printf("%4d",matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Ожидаемые ответы x = %d, y = %d, z = %d \n", matrix[3][0], matrix[3][1], matrix[3][2]);

    int a1 = matrix[0][0], b1 = matrix[0][1], c1 = matrix[0][2], d1 = matrix[0][3];
    int a2 = matrix[1][0], b2 = matrix[1][1], c2 = matrix[1][2], d2 = matrix[1][3];
    int a3 = matrix[2][0], b3 = matrix[2][1], c3 = matrix[2][2], d3 = matrix[2][3];
    float det, detx, dety, detz, x, y, z;

    // Вычисляем определитель матрицы системы и ее трех дополнительных матриц
    det = a1 * b2 * c3 + b1 * c2 * a3 + c1 * a2 * b3 - c1 * b2 * a3 - b1 * a2 * c3 - a1 * c2 * b3;
    detx = d1 * b2 * c3 + b1 * c2 * d3 + c1 * d2 * b3 - c1 * b2 * d3 - b1 * d2 * c3 - d1 * c2 * b3;
    dety = a1 * d2 * c3 + d1 * c2 * a3 + c1 * a2 * d3 - c1 * d2 * a3 - d1 * a2 * c3 - a1 * c2 * d3;
    detz = a1 * b2 * d3 + b1 * d2 * a3 + d1 * a2 * b3 - d1 * b2 * a3 - b1 * a2 * d3 - a1 * d2 * b3;

    // Проверяем, имеет ли система единственное решение
    if (det == 0) {
        printf("Система не имеет единственного решения.\n");
    } else {
        // Вычисляем неизвестные
        x = detx / det;
        y = dety / det;
        z = detz / det;
        printf("ответы x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
    }
}
int main() {
    system("chcp 65001");
    char test_file[] = "test.txt";

    FILE *file;
    file = fopen(test_file,"r");
    if (file == NULL) {
        printf("Error. Cannot find file. \n");
        system("pause");
    }
    printf("%s: \n", test_file);

    metod_cramera_from_txt(file);//1 test
    printf("Next Test \n");
    metod_cramera_from_txt(file);//2 test
    fclose(file);
    return 0;
}

