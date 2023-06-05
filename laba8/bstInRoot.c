/*
    - Вставка в корень, операция удаления элемента из  BST-дерева.
    1.	Сделайте вывод элементов в порядке их добавления в дерево (сразу, когда получаете случайные значения).
    2.	Добавьте в вывод элементов дерева информацию о количестве узлов в поддереве
    (например, выводите количество узлов в поддереве в скобках около каждого значения ключа)
    – так можно будет проанализировать, как выглядит дерево или реализуйте вывод древовидной структуры.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
//The elements of the number of the tree are set randomly, the elements of the tree are set with the area.
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void rotate_l(Node **root){
    Node *tmp;
    tmp=(*root)->right;
    (*root)->right=tmp->left;
    tmp->left=(*root);
    (*root)=tmp;
}
void rotate_r(Node **root){
    Node *tmp;
    tmp = (*root)->left;
    (*root)->left = tmp->right;
    tmp->right=(*root);
    (*root)=tmp;
}

/*Если ключ вставляемого элемента больше ключа корня,
 * то новый элемент становится корнем, старый корень и его левое поддерево – левым поддеревом,
 * правое поддерево старого корня – правым поддеревом.
 * Но в правом поддереве могут быть ключи, меньшие ключа нового элемента.
 *
 * Если ключ вставляемого элемента меньше ключа корня,
 * то новый элемент становится корнем, старый корень и его правое поддерево – правым поддеревом,
 * левое поддерево старого корня – левым поддеревом.
 * Но в левом поддереве могут быть ключи, большие ключа нового элемента.
*/
Node* insertionInLeaf(Node* Root, int key){
    if (Root == NULL){
        Node* newRoot = (Node*)malloc(sizeof(Node));
        newRoot -> data = key;
        newRoot ->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    }else{
        if (key >= Root->data ){
            Root->right = insertionInLeaf(Root->right, key);
        }else{
            Root->left = insertionInLeaf(Root->left, key);
        }
        return Root;
    }
}
void insertInRoot(Node **Root, int data){
    if (*Root == NULL){
        (*Root) = (Node*)malloc(sizeof(Node));
        (*Root)->data = data;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
//        (*Root)->elements = 1;
        return;
    }else{
        if (data >= ((*Root))->data){
            insertInRoot(&(*Root)->right, data);
            rotate_l((Root));

        }else{
            insertInRoot(&(*Root)->left, data);
            rotate_r(Root);
        }
    }
}

void printTree(Node* Root){
    if (Root != NULL) {
        printTree(Root->left);

        printf("%d ", Root->data);

        printTree(Root->right);
    }
}
void partition(Node **root, int k){
    if(*root == NULL) return;

    if((*root)->data > k){
        partition(&(*root)->left, k);
        rotate_r(root);
    }
    else if((*root)->data < k){
        partition(&(*root)->right, (k - (*root)->data - 1));
        rotate_l(root);
    }
}
//Function to find minimum in a tree.
Node* FindMin(Node* root)
{
    while(root->left != NULL) root = root->left;
    return root;
}
Node* deleteNode(Node *root, int elementToDelete){
    if (root == NULL) {
        return NULL;
    }

    if (elementToDelete > root->data) {
        root->right = deleteNode(root->right, elementToDelete);
        return root;
    }

    if (elementToDelete < root->data) {
        root->left = deleteNode(root->left, elementToDelete);
        return root;
    }
    else {
        // Case 1:  No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
            //Case 2: One child
        else if(root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
            // case 3: 2 children
        else {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
//    if (root->data == elementToDelete) {
//        if ((root->left == NULL) && (root->right == NULL)){
//            free(root);
//            return root
//        }else{
//            Node *temp =root
//            if (root->left == NULL && ((root)->right != NULL)) {
//                Node *rightSubRoot = temp->right;
//                root = rightSubRoot;
//                free(temp);
//                return;
//            }
//            if ((root)->right == NULL && ((root)->left != NULL)) {
//                Node *leftSubRoot = temp->left;
//                root = leftSubRoot;
//                free(temp);
//                return;
//            }
//            if (((root)->left != NULL) && ((root)->right != NULL)){
//                //find the largest node in left subtree
//                //copy the largest value of the left subtree into node to delete
//                //remove node whose value we copied
////                Node *leftSubTree = temp->left;
////                while (leftSubTree ) {
////                    if (leftSubTree->right == NULL){
////                        break;
////                    }
////                    leftSubTree = leftSubTree->right;
////                }
////                (root)->data = leftSubTree->data;
////                deleteNode(&(root), leftSubTree->data);
////                (root)->left = leftSubTree;
////                free(leftSubTree);
////                free(temp);
//                Node *rightSubRoot = temp->right;
//                Node *leftSubRoot = temp->left;
//
//                partition(&rightSubRoot, 0);
//                rightSubRoot->left = leftSubRoot;
//                root = rightSubRoot;
//                temp = NULL;
//                return;
//            }
//            return;
//        }
//
//    }
}

void print2console(Node *root, int space){
    if(root == NULL) return;

    space += 5;
    print2console(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    print2console(root->left, space);

}

// Вывод BST-дерева в консоль
void print2D(Node **root){
    print2console((*root), 0);
}
int main() {

    int i;
    srand(time(NULL));
    Node* Root = NULL;
    Node* RootLeaf = NULL;
    printf("Enter how many elements in the tree: ");
    int n,key;
    scanf("%d", &n);
    printf("\nElements: ");
    for (i = 0; i<n;i++){
        key = 30 + rand()%30;
        insertInRoot(&Root, key);
        RootLeaf = insertionInLeaf(RootLeaf, key);
        printf("%d ", key);
    }
    printf("\nTree: ");

    printf("In Leaf");
    print2D(&RootLeaf);
    printf("In Root");
    print2D(&Root);

    int elementToDelete = 11;
    printf("Which element do you want to delete? ");
    scanf("%d", &elementToDelete);
    Root = deleteNode(Root, elementToDelete);
    printf("\nTree after we deleted element '%d': \n", elementToDelete);

    printf("In Root");
//    printTree(Root);
//    printf("\n");
    print2D(&Root);

    return 0;
}
