
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_massiv(int n){
    srand(time(NULL));
    int *comb = (int*) malloc(sizeof(int)*n+1);
    comb[0] = rand()%n+1;
    for(int i = 1; i <= n; i++){
        comb[i] = rand()%n+1;
    }
    return comb;
}
void test_algoritm_without_rand(int n, int k){

    int *comb = (int*) malloc(sizeof(int)*k);//множество для проверки корректности вывода сочетаний
    for(int i = 0; i < k; i++){
        comb[i] = i;
    }

    /*while (1){
        for (int l = 1; l <= k; l++){
            printf("%3d", comb[l]);//вывод сочетания
        }
        printf("\n");
        int j = -1;
        for (int i = k-1; i >= 0; i--){
            if (comb[i] <= n-k+i){
                comb[i] += 1;
                j = i;
                break;
            }
        }
        if (j == -1){
            break;
        }
        for (int i = j+1; i < k; i++){
            comb[i] = comb[i-1]+1;
        }
    }*/
/*
    for (int i = 1; i < k; i++){
        comb[i] = i;
    }
    int j = 1;
    while (j != 0){//пока сочетание не состоит из последних наибольших чисел
        for (int l = 1; l <= k; l++){
            printf("%3d", comb[l]);//вывод сочетания
        }
        printf("\n");
        j = k;
        while (comb[j] == n-k+j){
            j --; //сдвигаемся на одну позицию влево
        }
        comb[j] += 1;
        for (int i = j+1; i < k; i++){
            comb[i] = comb[i-1] + 1;
        }
    }*/
    int i, j;

    while (1) {
        for (i = 0; i < k; i++) {
            printf("%d ", comb[i]);
        }
        printf("\n");

        for (i = k - 1; i >= 0; i--) {
            if (comb[i] != n - k + i + 1) {
                break;
            }
        }

        if (i < 0) {
            break;
        }

        comb[i]++;
        for (j = i + 1; j < k; j++) {
            comb[j] = comb[j - 1] + 1;
        }
    }
    printf("End of test algoritm\n");
    free(comb);
}
//генерация сочетаний без повторений и вывод в лексикографическом порядке
void generate_combination(int n, int k){
    int *comb = generate_massiv(n);

    comb[0] = -1; //сторожевой элемент
    for (int i = 1; i < k; i++){
        comb[i] = i;
    }
    int j = 1;
    while (j != 0){//пока сочетание не состоит из последних наибольших чисел
        for (int l = 1; l <= k; l++){
            printf("%3d", comb[l]);//вывод сочетания
        }
        printf("\n");
        j = k;
        while (comb[j] == n-k+j){
            j --; //сдвигаемся на одну позицию влево
        }
        comb[j] += 1;
        for (int i = j+1; i < k; i++){
            comb[i] = comb[i-1] + 1;
        }
    }
    free(comb);
}
int main(){
    system("chcp 65001");
    int k, n;
    printf("Мощность множества n:");
    scanf("%d", &n);
    printf("Мощность выборки k:");
    scanf("%d", &k);
    if (k > n || k == 0 || n == 0) {
        printf("Введены неверные данные");
        system("PAUSE");
        return 0;
    }
    test_algoritm_without_rand(n, k);
    printf("\n");
    //generate_combination(n, k);
    return 0;
}
