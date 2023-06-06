//Поиск подстроки в строке с помощью BST-дерева
//Написанная программа должна запрашивать у пользователя имя текстового файла и искомую подстроку;
// выводить в консоль номера позиций строки,
// с которых в тексте файла была найдена искомая подстрока.
// Программа должна работать с произвольным файлом (то есть, в файле может быть больше, чем одна строка).
// Например, на вход может быть подан файл с кодом программы или любой другой текстовый файл.\

//D://clion projects//hw4//hw4.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BST{
    char *word; // слово строки
    int position; // номер позиции строки, с которого начинается слово
    struct BST *right;
    struct BST *left;
}BST;

//strtok().strcmp().

//path = "D://clion projects//hw4//hw4.txt

void printTree(BST* Root){
    if (Root != NULL) {
        printTree(Root->left);

        printf("%s ", Root->word);

        printTree(Root->right);
    }
}
BST* insertionInLeaf(BST* Root, char* word,int position){
    if (Root == NULL){
        BST* newRoot = (BST*)malloc(sizeof(BST));
//        strcpy(newRoot->word, word);
        newRoot->word = word;
        newRoot->position = position;
        newRoot->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    }else{
        //if (strcmp(Root->word, word)>0){
        if (word[0] >= (Root->word)[0]){
            Root->right = insertionInLeaf(Root->right, word,position);
        }
        //if(strcmp(Root->word, word)<0){
        else{
            Root->left = insertionInLeaf(Root->left, word,position);
        }
        return Root;
    }
}
int search(BST* Root, char* word, int position) {
    if (Root == NULL) {
        printf("?Root is empty?");
        return 0;
    }
    if (strcmp(word, Root->word) == 0) {
        return Root->position;
    }
    if (strcmp(word, Root->word) < 0) {
        position += 1;
        Root->position = position;
        return search(Root->left, word, position);
    } else {
        position += 1;
        Root->position = position;
        return search(Root->right, word, position);
    }
//    BST* TempNode = Root;
//    while (TempNode) {
//        if (strcmp(TempNode->word, word) == 0)
//            return TempNode;
//        else if (word[0] >= (TempNode->word)[0])
//            TempNode = TempNode->right;
//        else
//            TempNode = TempNode->left;
//    }
//
//    return NULL;
}
BST* word_selection(char *path, BST* Root){

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Cannot open file");
        exit(1);
    }
    char str[1000];

    fgets(str, 1000, file);
    printf("Text from my txt file: \n%s", str);
    printf("\n--------\n");
    char *istr;
    int position = 0;
    istr = strtok (str," ");
//    printf("%s", istr);
    printf("\n");
//    insertionInLeaf(Root, istr);
    while(1){
        if (istr == NULL) break;
        printf("%s ", istr);
        Root = insertionInLeaf(Root, istr, position);
        position++;
        istr = strtok(NULL," ");//,;.!?

    }
    return Root;
}
int main() {
    BST* Root = NULL;
    char path[50] = "D://clion projects//hw4//hw4.txt";
    printf("Enter name of the file with text: ");
//    fgets(path, 50, stdin);
    printf("%s\n", path);
    int pos = strcspn(path, "\n"); // find position of first '\n' character
    if (pos != strlen(path)) path[pos] = '\0';

    Root = word_selection(path,Root);
//    printTree(Root);
    printf("\nEnter a word that you want to find: ");
    char search_string[100];
//    scanf("%s", search_string);
//    printf("%s", search_string);
    scanf("%[^\n]", search_string);

    int i = 0;
    while (search_string[i] != '\0') {
        printf("%c", search_string[i]);
        i++;
    }

//    fgets(search_string, 50, stdin);
//    int pos1 = strcspn(path, "\n"); // find position of first '\n' character
//    if (pos1 != strlen(path)) path[pos] = '\0';

//    char search_string[100] = "been";
//    while (getchar() != '\n')
//        ;

    int word_position;
     word_position = search(Root, search_string, 0);
    printf("\n Position of the string that you wanted to find: %d", word_position);

    return 0;
}
//D://clion projects//hw4//hw4.txt