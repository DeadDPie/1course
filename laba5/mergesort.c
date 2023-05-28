//merge sort
//абстрактно обменное
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//f - first inx l - last indx m - middle
int merge(int* x, int f, int m, int l){
	//abstract
	int sred = 0;
	int i = 0, j = l-f, k = f, w;
	int *x1 = (int*)malloc(sizeof(int)*(l-f+1));
	for(w = 0;w<m-f;w++){
		x1[w] = x[f+w];
		sred += 1;
	}
	for(w = l;w>=m;w--){
		x1[w-f] = x[m+(l-w)];
		sred += 1;
	}
	
	while(i<=j){
		if(x1[i]>x1[j]){
			x[k] = x1[j];
			sred += 2;
			j -= 1;
		}else{
			x[k] = x1[i];
			sred += 2;
			i += 1;
		}
		k += 1;
	}
	return sred;
}

int main(){
	int counts = 0, countp = 0; //количество сравнеенийи перестановок
	srand(time(NULL));
	
	int n,i,j;
	int sred = 0;
	printf("\nEnter size of array - ");
	scanf("%d", &n);
	
	int *x = (int*)malloc(sizeof(int)*n);
	
	printf("Unsorted array:\n");
	for(i=0;i<n;i++){
		x[i] = rand()%200-rand()%200;
		printf("%4d ",x[i]);
	}
	
	//ascending merge sort
	int h;
	for (h = 1; h<n;h*=2){
		for (i = 0; i < n - h;i+=h*2){
			if ((i +2*h-1) < n){
				counts += 1;
				sred += merge(x, i, i+h,i+h*2-1);
			}else{
				counts += 1;
				sred += merge(x, i, i+h, n-1);
			}
		}
	}
	
	printf("\nSorted massiv: \n");
	for(i=0;i<n;i++){
		printf("%4d ",x[i]);
	}
	
	sred += counts;
	sred += countp;
	printf("\n");

	printf("\n%d", sred);
	free(x);
	return 0;
}


