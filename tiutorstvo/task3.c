
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next; // ссылка на следующий узел
}Node;

typedef Node *PNode;

PNode Head = NULL;

PNode CreateNode (int n){
    PNode NewNode = (PNode)malloc(sizeof( Node)); // указатель на новый узел
    NewNode->number = n;
    NewNode->next = NULL; // следующего узла нет
    return NewNode; // результат функции - адрес узла
}

void AddFirst(PNode *Head, PNode NewNode){
    NewNode->next = *Head;
    *Head = NewNode;
}

void AddAfter (PNode p, PNode NewNode){
    NewNode->next = p->next;
    p->next = NewNode;
}

void AddLast(PNode *Head, PNode NewNode){
    PNode q = *Head;
    if (*Head == NULL) { // если список пуст,
        AddFirst(Head, NewNode); // вставляем первый элемент
        return;
    }
    while (q->next) q = q->next; // ищем последний элемент
    AddAfter(q, NewNode);
}

void show(PNode Head){
    if (Head == NULL){
        printf("List is empty\n");
        return;
    }
    PNode node = Head;
    while (node->next){
        printf("%d ", node->number);
        node = node->next;
    }
    return;
}


PNode read_lifo(char *name, PNode *Head){
    FILE *f = fopen(name, "r");
    if (f==NULL){
        printf("Error.\n");
        //system("pause");
        exit(0);
    }
    PNode New_head = *Head;
    int position = 0;
    while (!feof(f)) {
        int number;
        fscanf(f,"%d", &number);
        if (position %2 == 0){
            AddLast(&New_head,CreateNode(number));
        }else{
            AddFirst(&New_head,CreateNode(number));
        }
    }
    fclose(f);
    return New_head;
}

int main(){
    //system("chcp 65001");

    PNode q = read_lifo("../tiutorstvo/a.txt", &Head);
    show(q);

    return 0;
}




