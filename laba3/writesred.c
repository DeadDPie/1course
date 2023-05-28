#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_into_file(char* name, int n){
	n += 1;
	FILE *file = fopen(name,"a");
	if (file == NULL) {
		printf("Error. Cannot find file. \n");
		system("pause");
	return ; 
	}
	int counts, countp; //количество сравнеенийи перестановок
	int i, j, k;
	int sred = 0;
	int *x = NULL;
	for (k = 0; k < 5; k++){
		x = (int*)malloc(sizeof(int)*n);
		for(i=1;i<n;i++){
			x[i] = rand()%200-rand()%100;
		}
	x[0] = 1;
		//insert_sort
	for (i = 2; i<n; i++){
		x[0] = x[i]; //save value of insertation int
    	int j = i-1;
    	while (x[j] > x[0]) {//пока текущий элемент меньше предыущего
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
		free(x);
		counts = 0;
		countp = 0;
	}
	
	sred = sred/5;
	//printf("%d", sred);
	
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
		print_into_file("my.csv", n);
	}
	
	return 0;
}
