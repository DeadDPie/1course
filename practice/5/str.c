//Subbotina V-16
//Даны натуральное число n(пусть у меня это будет 800) и символы S1, …, Sn (строка).
//Подсчитать наибольшее количество идущих подряд одинаковых символов.
//The natural number n(800) and the symbols S1, ..., Sn (string) are given. Count the largest number of consecutive identical symbols.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    char file[] = "D://clion projects//practice//5//practice5.txt";
    int n = 800;
    char str[n];
    f = fopen(file, "r");

    if (f == NULL) {
        printf("Cannot open file");
        return 0;
    }

    fgets(str, n, f);
    printf("Text from my txt file: \n%s", str);

    int count = 1, maxc = 1;//string is not null
    //Count the largest number of consecutive identical symbols.
    for (int i = 0; i < n; i++){
        if (str[i]==str[i+1]){
            count +=1;
            if (maxc < count){
                maxc = count;
            }
        }else{
            count = 1;
        }
    }
    printf("\nThe largest number of consecutive identical symbols is %d\n", maxc);
    fclose(f);
    return 0;
}
