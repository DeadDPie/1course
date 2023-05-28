// Created by user on 09.03.2023.
//По наименованию товара выбрать товар с наименьшей ценой.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int price;
    int period;
}product;

void task(char *path){
    FILE *file = fopen(path, "r");
    if (file==NULL){
        printf("Error. Cannot find file.\n");
        system("pause");
        exit(0);
    }
    int num_products = 0;
    product products[100];//массив структур
    product cheapest;

    // чтение данных из файла в структуры
    while (fscanf(file, "%s %d %d", products[num_products].name, &products[num_products].price, &products[num_products].period) != EOF) {
        num_products++;
    }
    // закрытие файла
    fclose(file);

    char product_name[100];
    printf("Введите название товара: \n");
    scanf("%s", product_name);

    cheapest = products[0];
    // поиск товара с таким именем с наименьшей ценой
    for (int i = 1; i < num_products; i++) {
        if (!strcmp(products[i].name, product_name)){
            if (products[i].price < cheapest.price) {
                cheapest = products[i];
            }
        }
    }
    // вывод информации о товаре с наименьшей ценой
    printf("Товар %s, с наименьшей ценой: %.2d\n", product_name, cheapest.price);
}

int main() {
    system("chcp 65001");
    task("D://clion projects//practice//2//my.txt");
    return 0;
}