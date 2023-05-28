//LSD sorting of an array of strings. Strings consist of Latin alphabet characters.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void LSD_sort(char** arr, int size, int length, int d){
	int  R = 26, i, j;
	char tmp[size][length*2+1];

	int count[26] = {0};
		int r;
		
		// Count the frequency of each character
		for (i = 0; i < size; i++){
			count[arr[i][d]-(int)*"A"+1]++;
		}
		
		 //Compute the cumulative sum of the counts
        for (i = 2; i < R; i++)
            count[i] += count[i-1];

        // Move the strings to the auxiliary array in sorted order
        for (i = 0; i < size; i++)
            strcpy(tmp[count[arr[i][d]-(int)*"A"]++], arr[i]);

        // Copy the strings from the tmp array back to the original array
        for (i = 0; i < size; i++) {
            strcpy(arr[i], tmp[i]);
        }
}


int main(){
	int size;
	printf("\nEnter size of array : ");
	scanf("%d", &size);
	
	int length;
	printf("\nEnter lenght of str : ");
	scanf("%d", &length);
    
    // Выделяем память для массива строк
    int i;
    char **arr = (char **)malloc(size * sizeof(char *));
    for (i = 0; i < size; i++) {
        arr[i] = (char *)malloc((length + 1) * sizeof(char));
    }

    // Заполняем массив случайными символами
    int j;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < length; j++) {
            arr[i][j] = (char)(65 + rand()%26);
        }
        arr[i][length] = '\0';  // Добавляем нулевой символ в конец строки
    }
	
	printf("Unsorted array :\n");
    // Выводим массив на экран
    for (i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
    int d;
    for (d = length-1; d >=0 ; d--)
 		LSD_sort(arr,size,length, d);
 	
    printf("Sorted array : \n");
    for (i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }

    // Освобождаем память, выделенную для массива строк
    for (i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
	return 0;
}
