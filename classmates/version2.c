#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
		int a;
		int n;
		struct node *next;
} node;

node *add(node *top, int first, int sec){
	node *newel = (node*)malloc(sizeof(node));
	newel->a = first;
	newel->n = sec;
	newel->next = top;
	return newel;
}

void show(node *top){
	if (top == NULL){
		printf("Список пуст\n");
		return;
	}
	printf("P(x) = %dx^%d ", top->a, top->n);
	top = top->next;
	while (top){
		if (top->next)
			if (top->a > 0)
				printf("+%dx^%d ", top->a, top->n);
			else
				printf("%dx^%d ", top->a, top->n);
		else
			if (top->a > 0)
				printf("+%dx^%d\n", top->a, top->n);
			else
				printf("%dx^%d\n", top->a, top->n);
		top = top->next;
	}
	return;
}

node *reading_lifo_from_file(char *name){
	int i, a, n, kol;
	node *lifo = NULL;
	FILE *f = fopen(name, "r");
	if (f==NULL){
		printf("Файл не найден.\n");
		system("pause");
		exit(0);
	}
	printf("Введите количество количество элементов в многочлене:\n");
	scanf("%d", &kol);
    for (i=0; i<kol; i++){
    	fscanf(f, "%d", &a);
    	fscanf(f, "%d", &n);
    	if (a != 0)
    		lifo = add(lifo, a, n);
    }
    show(lifo);
    return lifo;
}

float VAL(node *P, int x){
	float otv = 0;
	while (P){
		if (P->n != 0)
			otv += pow(x, P->n) * P->a;
		else
			otv += P->a;
		P = P->next;
	}
	return otv;
}

int main(int argc, char *argv[]) {
    system("chcp 65001");
    float otv;
	int x;
    char name[] = "a.txt";
    node *P = reading_lifo_from_file(name);
    printf("Введите значение x: ");
    scanf("%d", &x);
    otv = VAL(P, x);
    printf("Ответ: %.3f\n", otv);
    system("pause");
    return 0;
}