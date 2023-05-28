#include <stdio.h>
#include <stdlib.h>
//часть алгоритма из методички не работает

void generate_combinations(int n, int k, int arr[], int len);

int main() {
    system("chcp 65001");
    int n, k, i;

    printf("Введите мощность множества n: ");
    scanf("%d", &n);

    printf("Введите мощность выборки k: ");
    scanf("%d", &k);

    if (k > n || k == 0 || n == 0) {
        printf("Введены неверные данные");
        system("PAUSE");
        return 0;
    }
    int arr[k];
    for (i = 0; i < k; i++) {
        arr[i] = i + 1;
    }

    generate_combinations(n, k, arr, k);

    return 0;
}
//Генерация сочетаний в лексикографическом порядке.
void generate_combinations(int n, int k, int arr[], int len) {
    int i, j;

    while (1) {
        for (i = 0; i < len; i++) {
            printf("%d ", arr[i]);//вывод сочетания
        }
        printf("\n");

        for (i = len - 1; i >= 0; i--) {//сдвигаемся на позицию влево
            if (arr[i] != n - len + i + 1) {
                break;
            }
        }

        if (i < 0) {//чтобы не вылететь за границы
            break;
        }

        arr[i]++;//увеличиваем на единицу элемент сочетания
        for (j = i + 1; j < len; j++) {
            arr[j] = arr[j - 1] + 1;
        }
    }
}
