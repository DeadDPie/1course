//сортировка подсчётом

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max (int d[], int len) {
    int maxval, i;

    maxval = d[0];
    for (i = 1; i < len; i++) {
        if (d[i] > maxval) {
            maxval = d[i];
        }
    }
    return maxval;
}

int min (int d[], int len) {
    int minval, i;

    minval = d[0];
    for (i = 1; i < len; i++) {
        if (d[i] < minval) {
            minval = d[i];
        }
    }
    return minval;
}


int main(){
	int counts = 0, countp = 0; //количество сравнеенийи перестановок
	srand(time(NULL));
	
	int n,i,j;
	int sred = 0;
	printf("\nEnter size of array - ");
	scanf("%d", &n);
	
	int *x = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		x[i] = rand()%200-rand()%200;
		printf("%4d ",x[i]);
	}
	
	int Min = min(x, n);
	int Max = max(x, n);
	
	printf("\nMin = %d, Max = %d", Min, Max);
	
	int range = 0;
	if (Min <= 0){//count size of count array
		range = abs(Min) + Max + 1;
	}
	else{
		range = abs(Min) + Max - 1;
	}
	
	int *c = (int*)malloc(sizeof(int)*range);//count array
	for(i=0;i<range;i++){
		c[i] = 0;//fill it with zeros
	}
	
	//counting sort
	printf("\nCount array: ");

	for (i = 0; i<n; i++){
		c[x[i]-Min] += 1;
		countp +=1;
	}
	for (i = 0; i<range; i++){
		printf("%4d ",c[i]);
	}

	int m = 0;
	if (Min <= 0){
		for (i = 0; i < range; i++){
			for (j = 0; j < c[i]; j++){
				x[m] = i - abs(Min);
				m++;
				countp += 1;
			}
		}
	}
	else{
		for (i = 0; i < Max + 1; i++){
			for (j = 0; j < c[i]; j++){
				x[m] = i ;
				m++;
				countp += 1;
			}
		}
	}
	sred += counts;
	sred += countp;
	printf("\n");

	printf("\nSorted massiv: \n");
	for(i=0;i<n;i++){
		printf("%4d ",x[i]);
	}
	printf("\n%d", sred);
	free(x);
	free(c);
	return 0;
}
