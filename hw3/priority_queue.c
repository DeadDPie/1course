#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
//path = "D://clion projects//hw3//hw3.txt";
int main(){
    printf("Enter name of file with elements of the queue: ");
    char path[50];
    fgets(path, 50, stdin);
    printf("%s\n", path);
    int pos = strcspn(path, "\n"); // find position of first '\n' character
    if (pos != strlen(path)) path[pos] = '\0';
    int* queue;
    int size = queue_size(path);
    queue = create_queue(path);
    printf("Queue: ");
    for (int i = 0; i < size; i++){
        printf("%d ",queue[i]);
    }

    printf("\nWhich element do you want to delete (enter value): ");
    int deleted;
    scanf("%d", &deleted);
    queue = delete(queue, size, deleted);
    size--;
    for (int i = 0; i < size; i++){
        printf("%d ",queue[i]);
    }

    printf("\nDo you want to delete max element?\n Enter 1 (if yes) or 0 (if no): ");
    int flag;
    scanf("%d", &flag);
    if (flag){
        queue = delete_max(queue, size);
        size--;
        for (int i = 0; i < size; i++){
            printf("%d ",queue[i]);
        }
    }else{
        printf("ok");
    }

    printf("\nWhich element do you want to insert in queue (enter value): ");
    int inserted;
    scanf("%d", &inserted);
    queue = insert(queue, size, inserted);
    size++;
    for (int i = 0; i < size; i++){
        printf("%d ",queue[i]);
    }

    printf("\nWhich element index do you want to find (enter value): ");
    int find;
    scanf("%d", &find);
    printf("%d", search(queue, size, find));


    printf("\nWhich element do you want to change (enter value): ");
    int to_change;
    scanf("%d", &to_change);
    printf("\nOn what element do you want it to be changed (enter value): ");
    int change;
    scanf("%d", &change);
    queue = change_value(queue, size, change, to_change);
    for (int i = 0; i < size; i++){
        printf("%d ",queue[i]);
    }

    return 0;
}