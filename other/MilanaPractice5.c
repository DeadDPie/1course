#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *f;
    char file[] = "input.txt";
    char str[1000];
    int count = 0;
    f = fopen(file, "r");

    if (f == NULL) {
        printf("error %s\n", file);
        return 0;
    }

    fgets(str, 1000, f);
    int i = 0;
    printf("The current text: \n%s", str);
    printf("\n");

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            count++;
        } else if(i == 0 || str[i-1] == ' ') {

            str[i] = toupper(str[i]);
        }
    }

    if(str[i-1] != ' ') {
        count++;
    }

    printf("\nThe number of words: %d\n", count);
    printf("\nThe result: \n%s", str);

    fclose(f);
    return 0;
}

