//Поиск подстроки в строке с помощью BST-дерева
//Написанная программа должна запрашивать у пользователя имя текстового файла и искомую подстроку; выводить в консоль номера позиций строки,
// с которых в тексте файла была найдена искомая подстрока.
// Программа должна работать с произвольным файлом (то есть, в файле может быть больше, чем одна строка).
// Например, на вход может быть подан файл с кодом программы или любой другой текстовый файл.\

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BST{
    char *word; // слово строки
    int pos; // номер позиции строки, с которого начинается слово
    struct BST *right;
    struct BST *left;
}
BST* Root;
Root = NULL;
/*typedef struct node{
        int data;
        struct node *left;
        struct node *right;
        } Node;
*/
//strtok().strcmp().
//path = "D://clion projects//hw3//hw3.txt
int make_bst(char *file, struct BST ** Root){
    FILE *f;
    //char file[] = "D://clion projects//practice//5//practice5.txt";
    int n = 800;
    char str[n];
    f = fopen(file, "r");

    if (f == NULL) {
        printf("Cannot open file");
        return 0;
    }

    fgets(str, n, f);
    printf("Text from txt file: \n%s", str);
    if (*Root == NULL){
        struct BTS Root = ()malloc(sizeof(BTS));
        *Root->word = searchword;
        *Root -> left = NULL;
        *Root->right = NULL;
        return 0;
    }else{
        if (strcmp(searchword,*Root->word) == ){
            *Root->right = searchword;
        }else{
            *Root->right = NULL;
        }
        return 0;
    }
}

void bst(){

}
int main() {
    printf("Enter name of the file with text: ");
    char path[50];
    fgets(path, 50, stdin);
    printf("%s\n", path);
    int pos = strcspn(path, "\n"); // find position of first '\n' character
    if (pos != strlen(path)) path[pos] = '\0';
    printf("Enter string that you want to find: ");
    char search_string[100];
}