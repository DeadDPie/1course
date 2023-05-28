//Метод вставки со сторожевым элементом (II)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int counts, countp; //количество сравнеенийи перестановок
	srand(time(NULL));
	
	int n,i,j;
	int sred = 0;
	printf("\nEnter size of array - ");
	scanf("%d", &n);
	
	n += 1;
	int *x = (int*)malloc(sizeof(int)*n);
	x[0] = 1;
	printf("%d", x[0]);
	for(i=1;i<n;i++){
		x[i] = rand()%200-rand()%100;
		printf("%4d ",x[i]);
	}
	
	//insert_sort
	for (i = 2; i<n; i++){
		x[0] = x[i]; //save value of insertation int
    	int j = i-1;
    	while ( x[j] > x[0]) {//пока текущий элемент меньше предыущего
    		counts += 1;
      		x[j+1] = x[j];//меняем текущий элемент на предыдущий
      		countp += 1;
      		j = j-1;
    	}
    	x[j+1] = x[0];
    	countp += 1;
	}
	sred += counts;
	sred += countp;
	printf("\n");


	printf("\nSorted massiv: \n");
	for(i=0;i<n;i++){
		printf("%4d ",x[i]);
	}
	printf("\n%d", counts);
	free(x);
	return 0;
}
