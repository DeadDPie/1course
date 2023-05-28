

#ifndef CLIONPROJECT_FUNCTIONS_H
#define CLIONPROJECT_FUNCTIONS_H
//•	Создание очереди из N элементов (N и значения самих элементов читать из текстового файла, имя файла запрашивать с клавиатуры)
int* create_queue(char *path);
//•	Добавление нового элемента в очередь
int* insert(int* arr, int size, int value);
//•	Удаление элемента с максимальным значением
int* delete_max(int* arr, int size);
//•	Удаление любого элемента с заданным значением
int* delete(int* arr, int size, int value);
//•	Поиск элемента с заданным значением
int search(int* arr, int size, int value);
//•	Изменение значения выбранного элемента
int* change_value(int* arr, int size, int changeable, int changing);
int queue_size(char *path);
#endif //CLIONPROJECT_FUNCTIONS_H
