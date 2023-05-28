//Функцию создания двоичного файла, содержащего матрицу целых чисел размерности n*n.
// Значение n задается с клавиатуры. Элементы матрицы - целые случайные числа.
//- Функция печати содержимого файла.
//- Функцию вычисляющую сумму элементов заданного столбца. Всю матрицу при этом просматривать нельзя.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** binary_file_w_matrix(char* name, int n){
    FILE *binary_file = fopen(name,"wb");

    if (binary_file == NULL) {
        printf("Error. Cannot create file. \n");
        system("pause");
    }
    int **x, i, j;
    x=(int**)malloc(sizeof(int*)*n);
    for(i = 0; i < n; i++)
        x[i] = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            x[i][j] = rand()%40;
            fwrite(&x[i][j], sizeof(int), 1, binary_file);
        }
    }
    fclose(binary_file);
    return x;
}
void print_file(char* name, int n){
    FILE *binary_file = fopen(name,"rb");
    if (binary_file == NULL) {
        printf("Error. Cannot find file. \n");
        system("pause");
        return ;
    }
    int number;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fread(&number, sizeof(int), 1, binary_file);
            printf("%4d", number);
        }
        printf("\n");
    }
    printf("\n");
    fclose(binary_file);
}
int column_sum(int **x, int n, int c){
    int csum = 0;
    for (int i = 0; i < n; i++)
        csum += x[i][c];
    return csum;
}

int main(){
    srand(time(NULL));
    int n, column;
    printf("Enter matrix size: ");
    scanf("%d",&n);
    int **x = binary_file_w_matrix("a.txt", n);
    print_file("a.txt", n);
    printf("Enter column number to sum: ");
    scanf("%d",&column);
    printf("%d", column_sum(x, n, column-1));
}