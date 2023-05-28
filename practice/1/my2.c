#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_file(char* name, int n){
    int i;
    FILE *binary_file = fopen(name,"wb");

    if (binary_file == NULL) {
        printf("Error. Cannot create file. \n");
        system("pause");
        return ;
    }
    fwrite(&n, sizeof(int), 1, binary_file);//in the begining write quantity of numbrs in file
    for(i = 0; i < n; i++){
        int number = rand()%100-rand()%100+3;
        fwrite(&number, sizeof(int), 1, binary_file);
    }
    fclose(binary_file);
}


void print_file(char* name){
    FILE *binary_file = fopen(name,"rb");
    if (binary_file == NULL) {
        printf("Error. Cannot find file. \n");
        system("pause");
        return ;
    }
    int n;
    fread(&n, sizeof(int), 1, binary_file);
    printf("%s: \n", name);

    int i;
    for (i = 0; i < n; i++){
        int number;
        fread(&number, sizeof(int), 1, binary_file);//считываем число(переводя из 2ич в 10ич сис

        if (i % 10 == 0){
            printf("\n\t");
        }
        printf("%5d", number);//печатаем его в 10ич сис
    }
    printf("\n");
    fclose(binary_file);
}

int min_elem(char *name, int place, int dif){
    int i, min, elem;
    FILE *f = fopen(name, "rb");
    if (f==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return 0;
    }
    fseek(f, place, SEEK_SET);// устанавливает указатель place позиции файла from beggining because of SEEK_SET
    fread(&min, sizeof(int), 1, f);
    for (i=0; i<dif-1; i++){
        fread(&elem, sizeof(int), 1, f);
        if (elem < min)
            min = elem;
    }
    return min;
}

int max_elem(char *name, int place, int dif){
    int i, max, elem;
    FILE *f = fopen(name, "rb");
    if (f==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return 0;
    }
    fseek(f, place, SEEK_SET);
    fread(&max, sizeof(int), 1, f);
    for (i=0; i<dif-1; i++){
        fread(&elem, sizeof(int), 1, f);
        if (elem > max)
            max = elem;
    }
    return max;
}

void create_file_from_files(char* file_name1, char* file_name2, char* new_file_name){

    FILE *binary_file1 = fopen(file_name1, "rb");
    if (binary_file1==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return;
    }

    FILE *binary_file2 = fopen(file_name2, "rb");
    if (binary_file2==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return;
    }

    int len1, len2, min, flag, dif, kol;
    fread(&len1, sizeof(int), 1, binary_file1);
    fread(&len2, sizeof(int), 1, binary_file2);
    //check which is longer and remember in flag
    if (len1<len2){
        min = len1;
        flag = 1;
        dif = len2-len1;
    }
    else{
        min = len2;
        flag = 2;
        dif = len1-len2;
    }
    if (len1==len2)
        flag = 3;
    //calculate lenght of new file
    kol = len1 + len2 - dif + 2; //each element without some from largef + 2 in the end

    FILE *new_binary_file = fopen(new_file_name, "wb");
    if (new_binary_file==NULL){
        printf("Файл не найден.\n");
        system("pause");
        return;
    }
    fwrite(&kol, sizeof(int), 1, new_binary_file);//write lenght of new file in the begining
    //add numbers like in task
    int i;
    for (i = 0; i < min; i++){
        int number1;
        int number2;
        fread(&number1, sizeof(int), 1, binary_file1);
        fread(&number2, sizeof(int), 1, binary_file2);

        if (number1 > number2){
            fwrite(&number1, sizeof(int), 1, new_binary_file);
            fwrite(&number2, sizeof(int), 1, new_binary_file);
        } else {
            fwrite(&number2, sizeof(int), 1, new_binary_file);
            fwrite(&number1, sizeof(int), 1, new_binary_file);
        }
    }
    int place = ftell(binary_file1);//возвращает текущее значение указателя положения в файле для указанного потока
//и в первом и в втором файле указатель стоит на одном и том же месте

    //From the "remainder" of a long file, add the maximum and minimum components to the end of the new one
    int min_element;
    int max_element;
    if (flag == 1){
        min_element = min_elem(file_name2, place, dif);
        max_element = max_elem(file_name2, place, dif);
        fwrite(&max_element, sizeof(int), 1, new_binary_file);
        fwrite(&min_element, sizeof(int), 1, new_binary_file);
    }
    if (flag == 2){
        min_element = min_elem(file_name1, place, dif);
        max_element = max_elem(file_name1, place, dif);
        fwrite(&max_element, sizeof(int), 1, new_binary_file);
        fwrite(&min_element, sizeof(int), 1, new_binary_file);
    }
    fclose(binary_file1);
    fclose(binary_file2);
    fclose(new_binary_file);

    remove(file_name1);
    remove(file_name2);
}




int main(int argc, char *argv[]){
    system("chcp 65001");
    srand(time(NULL));

    int len1, len2, min, max;
    char file_name1[] = "FILE1";
    char file_name2[] = "FILE2";
    char new_file_name[30];

    printf("Введите количество чисел в FILE1:\n");
    scanf("%d", &len1);
    printf("Введите количество чисел в FILE2:\n");
    scanf("%d", &len2);

    create_file(file_name1, len1);
    create_file(file_name2, len2);

    print_file(file_name1);
    print_file(file_name2);

    printf("Введите название создаваемого файла:\n");
    scanf("%s", new_file_name);

    create_file_from_files(file_name1, file_name2, new_file_name);
    print_file(new_file_name);

    system("pause");
    return 0;
}




