//
// Created by user on 08.03.2023.
//Составить список по заданному наименованию товара и объему экспорта.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char country[50];
    char product[30];
    int export;
}Matrix_row;


void read_file(char *path){
    FILE *f = fopen(path, "r");
    if (f==NULL){
        printf("Error.\n");
        system("pause");
        exit(0);
    }
    Matrix_row matrix_rows[30];//массив структур ряд_матрицы
    char *token;
    char line[500];
    int i = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        printf("line %s", line);// считываем строку из файла
        token = strtok(line, " ");
        printf("token %s", token);// разбиваем строку на части с помощью пробела
        strcpy(matrix_rows[i].country, token); // копируем имя страны в поле структуры
        token = strtok(NULL, " ");
        strcpy(matrix_rows[i].product, token); // копируем наименоание продукта в поле структуры
        token = strtok(NULL, "\n");
        matrix_rows[i].export = atoi(token); // преобразуем количество экспорта из строки в целое число и записываем в поле структуры
        i++;
    }
    char Country[50];
    printf("Enter the name of the country: \n");
    gets(Country);


    for (int j = 0; j < 28; j++){
        int is_country = strcmp(matrix_rows[j].country, Country);
        printf("%s", matrix_rows[j].country);
        /*if (is_country == 0) {
            is_country = 1;
        } else {
            is_country = 0;
        }*/
        if (is_country){
            printf("\nProduct : %s --- Export : %d", matrix_rows[j].product, matrix_rows[j].export);
        }
        else{
            printf("Error ");
        }
    }
    fclose(f);

}
/*
void run_task(Matrix_row *matrix_row){
    char Country[50];
    printf("Enter the name of the country: \n");
    gets(Country);
    int is_country = strcmp(matrix_row->country, Country);
    if (is_country == 0) {
        is_country = 1;
    } else {
        is_country = 0;
    }
    for (int j = 0; j < 28; j++){
        if (is_country){
            printf("Product : %s --- Export : %d", matrix_row[j].product, matrix_row[j].export);
        }
    }

}
 */
int main(){
    //run_task(read_file("test.txt"));
    read_file("test.txt");
    return 0;
}
