
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
//•	Создание очереди из N элементов (N и значения самих элементов читать из текстового файла, имя файла запрашивать с клавиатуры)

int* create_queue(char *path){

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Cannot open file");
        exit(1);
    }
    int n;
    fscanf(file,"%d", &n);//scanf from file size of queue
    int *array = (int *)calloc(sizeof(int), n);

    for (int i = 0; i < n; i++){
        fscanf(file,"%d", &array[i]);
    }
    //insert_sort ascending order (min left max right)
    for (int i = 1; i<n; i++){
        int buf = array[i]; //save value of insertation int
        int j = i-1;
        while (j >= 0 && array[j] > buf) {//пока текущий элемент меньше предыущего
            array[j+1] = array[j];//меняем текущий элемент на предыдущий
            j = j-1;
        }
        array[j+1] = buf;
    }
    fclose(file);
    return array;
}

//•	Добавление нового элемента в очередь
int* insert(int* arr, int size, int value){
    int *new_array = (int *)calloc(sizeof(int), size + 1);
    // Находим индекс, по которому нужно вставить новый элемент в массив
    int new_position = size;
    for (int i = 0; i < size; i++) {
        if (value < arr[i]) {
            new_position = i;
            break;
        }
    }
    for (int i = 0; i < new_position; i++){
        new_array[i] = arr[i];
    }
    // Вставляем новый элемент в массив на позицию, найденную на предыдущем шаге
    new_array[new_position] = value;
    if (new_position < size){
        for (int i = new_position; i < size; i++){
            new_array[i+1] = arr[i];
        }
    }

    free(arr);
    arr = new_array;
    return arr;
}

//•	Удаление элемента с максимальным значением
int* delete_max(int* arr, int size){
    int *new_array = (int *)calloc(sizeof(int), size - 1);
    for (int i = 0; i < size-1; i++){
        new_array[i] = arr[i];
    }
    free(arr);
    arr = new_array;
    return arr;
}

//•	Удаление любого элемента с заданным значением
int* delete(int* arr, int size, int value){
    int index = search(arr,size,value);
    if (index == -1){
        printf("There is no element with such value\n" );
        return arr;// return how it was without changes
    }
    int *new_array = (int *)calloc(sizeof(int), size - 1);

    for (int i = 0; i < index; i++){
        new_array[i] = arr[i];
    }
    for (int i = index; i < size-1; i++){
        new_array[i] = arr[i+1];
    }
    free(arr);
    arr = new_array;
    return arr;

}

//•	Поиск элемента с заданным значением
int search(int* arr, int size, int value){
    int l = 0, r = size-1; // left, right, middle borders
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if value is present at mid
        if (arr[m] == value)
            return m;

        // If value greater, ignore left half
        if (arr[m] < value)
            l = m + 1;

            // If value is smaller, ignore right half
        else
            r = m - 1;
    }
    return -1;
}

//•	Изменение значения выбранного элемента
int* change_value(int* arr, int size, int changeable, int to_change){
    arr = delete(arr, size, to_change);
    size--;
    arr = insert(arr, size,changeable);
    return arr;

}
int queue_size(char *path){
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Cannot open file");
        exit(1);
    }
    int n;
    fscanf(file,"%d", &n);//scanf from file size of queue
    fclose(file);
    return n;
}