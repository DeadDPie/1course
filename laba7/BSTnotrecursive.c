//Создание BST-дерева методом вставки в лист(не рекурсивная реализация).
// Рекурсивная функция печати элементов дерева (прямой обход дерева)
//Creating a BST tree by inserting into a leaf (not a recursive implementation). 
//Recursive function to print tree elements (direct tree traversal)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* make_BST(Node **Root, int key){
    if (*Root == NULL){
        *Root = (Node*)malloc(sizeof(Node));
        (*Root)->data = key;
        (*Root)->left = NULL;
        (*Root)->right = NULL;

        return;
    }else{
    	Node *temp = *Root;
    	while (temp != NULL){
    		if (key >= temp->data){
    			if (temp->right == NULL){
    				(temp->right)= (Node*)malloc(sizeof(Node));
    				temp->right->left = NULL;
    				temp->right->right = NULL;
    				temp->right->data = key;
    				return;
				}else{
					temp = temp->right;
				}
			}else{
				if (temp->left == NULL){
					(temp->left)= (Node*)malloc(sizeof(Node));
					temp->left->left = NULL;
        			temp->left->right = NULL;
           			temp-> left->data = key;
           			return;
				}else{
					temp = temp->left;
				}
			}
		}
        
        return ;
    }
}

void printTree(Node* Root){
    if (Root == NULL) {
    	return;
	}else{
		printf("%d ", Root->data);
        printTree(Root->left);
        printTree(Root->right);
	}
    
}

int main() {
    Node* Root = NULL;
    srand(time(NULL));
    printf("Enter how many elements in the three: ");
    int n,key;
    scanf("%d", &n);
	int i;

    for (i = 0; i<n;i++){
        key = 30 + rand()%30;
        make_BST(&Root, key);
    }
    printTree(Root);
    
    return 0;
}
