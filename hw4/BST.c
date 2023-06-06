//Поиск подстроки в строке с помощью BST-дерева
//Написанная программа должна запрашивать у пользователя имя текстового файла и искомую подстроку;
// выводить в консоль номера позиций строки,
// с которых в тексте файла была найдена искомая подстрока.
// Программа должна работать с произвольным файлом (то есть, в файле может быть больше, чем одна строка).
// Например, на вход может быть подан файл с кодом программы или любой другой текстовый файл.\

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BST{
    char *word; // слово строки
    int position; // номер позиции строки, с которого начинается слово
    struct BST *right;
    struct BST *left;
}BST;

BST* insertionInLeaf(BST* Root, char* word,int position){
    if (Root == NULL){
        BST* newRoot = (BST*)malloc(sizeof(BST));
        newRoot->word = word;
        newRoot->position = position;
        newRoot->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    }else{
        if (word[0] >= (Root->word)[0]){
            Root->right = insertionInLeaf(Root->right, word,position);
        }
        else{
            Root->left = insertionInLeaf(Root->left, word,position);
        }
        return Root;
    }
}
int search(BST* Root, char* word, int position) {
    if (Root == NULL) {
        printf("There is no such word");
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
}
BST* word_selection(char *path, BST* Root){

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Cannot open file");
        exit(1);
    }
    char str[10000];

    fgets(str, 10000, file);
    printf("Text from my txt file: \n%s", str);
    printf("\n--------\n");
    char *istr;
    int position = 1;
    istr = strtok (str," ");
    printf("All words from the text:\n");
    while(1){
        if (istr == NULL) break;
        printf("%s ", istr);
        Root = insertionInLeaf(Root, istr, position);
        position++;
        istr = strtok(NULL," ,;.!?");

    }
    return Root;
}
int main() {
    BST* Root = NULL;
    char path[500];
    printf("Enter name of the file with text: ");
    fgets(path, 50, stdin);
    printf("%s\n", path);
    int pos = strcspn(path, "\n"); // find position of first '\n' character
    if (pos != strlen(path)) path[pos] = '\0';

    Root = word_selection(path,Root);

    char search_string[1500];
    printf("\n--------\n");
    printf("\nEnter a word that you want to find: ");

    fgets(search_string, sizeof(search_string), stdin);
    if (search_string[strlen(search_string) - 1] == '\n') {
        search_string[strlen(search_string) - 1] = '\0';
    }

    int word_position = 0;
    word_position = search(Root, search_string, 1);
    printf("\nYour word is %d word", word_position);

    return 0;
}
