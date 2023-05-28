//В текстовом файле записано одно число N.
// Считать информацию из файла. Дописать в исходный файл последовательность 1, 2, 3, ...N.

#include <stdio.h>
#include <stdlib.h>

int read_files_number(char* name){
    FILE *file = fopen(name,"r");
    int number = 0;

    if (file == NULL) {
        printf("Error. Cannot read file. \n");
        system("pause");
        return EXIT_FAILURE;
    }
    int check = fscanf(file,"%d",&number);
    if (check < 1){
        printf("There are no numbers \n");
        system("pause");
        return EXIT_FAILURE;
    }
    printf("%d\n", number);
    fclose(file);
    return number;
}

int write_sequence_to_file(char* name, int n){
    FILE *file = fopen(name,"w");

    if (file == NULL) {
        printf("Error. Cannot open file. \n");
        system("pause");
        return EXIT_FAILURE;
    }
    if (n <= 0){
        printf("Error. number < 0");
        system("pause");
        return EXIT_FAILURE;
    }
    else{
        for (int i = 1; i <= n; i++){
            fprintf(file, "%d ", i);
            printf("%d ",i);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
int main() {
    int n = read_files_number("sequence.txt");
    write_sequence_to_file("sequence.txt", n);
}