//Функцию создания двоичного файла, содержащего матрицу целых чисел размерности n*n.
// Значение n задается с клавиатуры. Элементы матрицы - целые случайные числа.
//- Функция печати содержимого файла.
//- Функцию вычисляющую сумму элементов заданного столбца. Всю матрицу при этом просматривать нельзя.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binary_file_w_matrix(char* path, int n){
    srand(time(NULL));
    FILE *binary_file = fopen(path,"wb");
    if (!binary_file) {
        perror(path);
        return EXIT_FAILURE;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num = rand()%40;
            fwrite(&num, sizeof(int), 1, binary_file);
        }
    }
    fclose(binary_file);
    return EXIT_SUCCESS;
}
int print_file(char* path, int n){
    FILE *binary_file = fopen(path,"rb");
    if (!binary_file) {
        perror(path);
        return EXIT_FAILURE;
    }
    int number = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fread(&number, sizeof(int), 1, binary_file);
            printf("%4d", number);
        }
        printf("\n");
    }
    printf("\n");
    fclose(binary_file);
    return EXIT_SUCCESS;
}
int column_sum(char* path, int n, int c){
    FILE *binary_file = fopen(path,"rb");
    if (!binary_file) {
        perror(path);
        return EXIT_FAILURE;
    }
    int number = 0, csum = 0;;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fread(&number, sizeof(int), 1, binary_file);
            if (j == c ){
                csum += number;
            }
        }
    }
    fclose(binary_file);
    return csum;
}

int main(){
    int n, column;

    printf("Enter matrix size: ");
    scanf("%d",&n);
    binary_file_w_matrix("a.txt", n);
    print_file("a.txt", n);

    printf("Enter column number to sum: ");
    scanf("%d",&column);
    printf("%d", column_sum("a.txt", n, column-1));
}