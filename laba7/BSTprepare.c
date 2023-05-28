#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* Root, int key){
    if (Root == NULL){
        Node* newRoot = (Node*)malloc(sizeof(Node));
        newRoot -> data = key;
        newRoot ->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    }else{
        if (key >= Root->data ){
            Root->right = insert(Root->right, key);
        }else{
            Root->left = insert(Root->left, key);
        }
        return Root;
    }
}
void printTree(Node* Root){
    if (Root != NULL) {
        printTree(Root->left);

        printf("%d ", Root->data);

        printTree(Root->right);
    }
}


int main() {
    Node* Root = NULL;
    srand(time(NULL));
    printf("Enter how many elements in the three: ");
    int n,key;
    scanf("%d", &n);

    for (int i = 0; i<n;i++){
        key = 30 + rand()%30;
        Root = insert(Root, key);
    }
    printTree(Root);
    return 0;
}