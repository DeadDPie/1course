#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// функция для печати массива
void print_array(char** arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        printf("%s           ", arr[i]);
    printf("\n");
}

// определить случайное число от a до b
int randomchik(int a, int b)
{
    return a + rand() % (b - a);
}

// создать массив строк
char** create_array(int size, int len)
{
    int j;
    char** arr = (char**)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * (len+1));
        for ( j = 0; j < len; j++)
            arr[i][j] = (char)(randomchik(48, 57));

        arr[i][j] = '\0';
    }
    return arr;
}

// получить код символа с индексом index из строки str gj
int get_code_by_ind(char* str, int index)
{
    if (index < strlen(str))
        return (int)str[index];
    return -1;;
}

// сортировка подсчетом
char** count_sort(char** arr, int arrSize, int index)
{
    int supportSize = 256;
    int* support = (int*)malloc(sizeof(int) * supportSize);//создаем вспомогательную последовательность из 256 элементов
    memset(support, 0, sizeof(int) * supportSize);//заполняю нулями

    for (int i = 0; i < arrSize; i++)
        support[get_code_by_ind(arr[i], index)]++;//заполняем как asti код

    int size = arrSize;
    //идем с конца

    for (int i = supportSize - 1; i >= 0; i--)
    {
        size -= support[i];
        support[i] = size;
    }

    char** result = (char**)malloc(sizeof(char*) * arrSize);

    for (int i = 0; i < arrSize; i++)
        result[support[get_code_by_ind(arr[i], index)]++] = arr[i];

    free(support);

    return result;
}

char** LSD_sort(char** arr, int arrSize)
{
    int maxLength = strlen(arr[0]);
    for (int i = maxLength - 1; i >= 0; i--)
        arr = count_sort(arr, arrSize, i);
    return arr;
}

int main(){
    system("chcp 1251");
    srand(time(0));

    int arrSize;
    int maxLength;
    printf("Введите количество слов: ");
    scanf("%d", &arrSize);
    printf("Введите размер слов: ");
    scanf("%d", &maxLength);

    char** arr = create_array(arrSize, maxLength);

    printf("исходный массив:\n");
    print_array(arr, arrSize);

    arr = LSD_sort(arr, arrSize);

    printf("отсортированный массив:\n");
    print_array(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
        free(arr[i]);
    free(arr);

    return 0;
}


