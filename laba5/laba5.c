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

void print_into_file(char* name, int n){
	FILE *file = fopen(name,"a");
	if (file == NULL) {
		printf("Error. Cannot find file. \n");
		system("pause");
	return ; 
	}
	
	int counts = 0, countp = 0; //количество сравнеенийи перестановок
	int i, j, k;
	int sred = 0;
	for (k = 0; k < 5; k++){
		int *x = (int*)malloc(sizeof(int)*n);

		for(i=0;i<n;i++){
			x[i] = rand()%200-rand()%200;
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

		sred += counts;
		sred += countp;
		free(x);
		counts = 0;
		countp = 0;
	}
	
	sred = sred/5;
	
 	fprintf(file,"%d;%d\n", n, sred);

	fclose(file);
	return;
}

int main(){

	srand(time(NULL));
	
	int i,j,n;
	for (i=1; i<=19; i++){
		if (i<=10)
			n = i*100;
		else
			n = (i%10)*1000 + 1000;
		print_into_file("mycsv.csv", n);
	}
	
	return 0;
}
