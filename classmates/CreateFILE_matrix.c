#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Написать:
//- Функцию создания двоичного файла, содержащего матрицу целых чисел размерности n*n. Значение n задается с клавиатуры. Элементы матрицы - целые случайные числа.
//- Функция печати содержимого файла.
//- Функцию вычисляющую сумму элементов заданного столбца. Всю матрицу при этом просматривать нельзя.

void create_file(char *name, int n){
    int i;
    FILE *f = fopen(name, "wb");
    if (f==NULL){
        printf("Ошибка создания файла\n");
        system("pause");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    for (i=0; i<n*n; i++){
        int z = rand()%100;
        fwrite(&z, sizeof(int), 1, f);
    }
    fclose(f);
}




void read_file(char *name){
    int n;
    FILE *f = fopen(name, "rb");
    if (f==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return;
    }
    int i;
    int z;
    fread(&n, sizeof(int), 1, f);
    printf("\n%d",n);
    while(!feof(f)){
        if (i>=n&&i%n==0)
            printf("\n");
        if (fread(&z, sizeof(int), 1, f)!=1)
            break;
        printf("%5d", z);
        i++;
        }
    fclose(f);
    printf("\n");
}


int sum_number_colown(char*name,int n,int del){
	FILE *f = fopen(name, "rb");
    if (f==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return 0;
    }
	int **x=NULL;
	int sum=0;
	int i,j;
	int k=del-1;
	x=(int**)malloc(sizeof(int*)*n);
	for(i=0 ; i < n ; i++)
	{
		x[i]=(int*)malloc(sizeof(int)*n);
	}
	fread(&n, sizeof(int), 1, f);
	
	for (i = 0 ; i < n ; i++){
		for (j = 0 ; j < n ; j++)
			fread(&x[i][j], sizeof(int), 1, f); 
	}
	fclose(f);
	printf("Matrix\n");
		
	for (i = 0 ; i < n ; i++){
		for ( j = 0 ; j < n ; j++)
			printf("%3d",x[i][j]);
		printf("\n");
	}
	
	for (int i=0;i<n;i++){
		sum+=x[i][k];
	}
return sum;

}
	


int main(int argc, char *argv[]) {
    system("chcp 65001");
    int n, m, k;
    char name[30];
    srand(time(NULL));
    printf("Введите размерность матрицы n x n:\n");
    scanf("%d", &n);
    printf("Введите название файла:\n");
    scanf("%s", name);
    create_file(name, n);
    read_file(name);
    printf("Введите столбец ,для которого нужно посчитать сумму:\n");
    scanf("%d",&k);
    printf("Cумма столбца под номером %d равна %d ",k,sum_number_colown(name,n,k));
	return 0;}
	
	
	