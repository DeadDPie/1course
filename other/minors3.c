#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    system("chcp 65001");
    int **x, n = 4, i, j;
    srand(time(NULL));
    printf("размер матрицы - 4");
    x=(int**)malloc(sizeof(int*)*n); //создаём матрицу
    for(i = 0; i < n; i++)
        x[i] = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            x[i][j] = rand()%20;} //заполняем рандомными значениями до 40
    }
    printf("\nМатрица:  \n");
// печать элементов матрицы x
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%4d",x[i][j]);
        printf("\n");
    }


    printf("\nМиноры: \n");
    for (int s = 0; s < n; s++){
        for (int m = 0; m < n; m++){
            printf("\nМинор: \n");
            for(i = 0; i < n ; i++){
                for(j = 0; j < n; j++){
                     if ((s != i) && (m != j))printf("%4d",x[i][j]);
                }
                printf("\n");
            }
            printf("\n");

        }
    }

    for(i = n-1; i >= 0; i--)
        free( x[i]);
    free(x);
    return 0;
}