#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int counts, countp; //���������� ����������� ������������
	srand(time(NULL));
	
	int n,i,j;
	int sred = 0;
	printf("\nEnter size of array - ");
	scanf("%d", &n);

	int *x = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		x[i] = rand()%200-rand()%100;
		printf("%4d ",x[i]);
	}
	
	//insert_sort
	for (i = 1; i<n; i++){
		int buf = x[i]; //save value of insertation int
    	int j = i-1;
    	while (j >= 0 && x[j] > buf) {//���� ������� ������� ������ ����������
    		counts += 2;
      		x[j+1] = x[j];//������ ������� ������� �� ����������
      		countp += 1;
      		j = j-1;
    	}
    	x[j+1] = buf;
    	countp += 1;
	}
	sred += counts;
	sred += countp;
	printf("\n");


	printf("\nSorted massiv: \n");
	for(i=0;i<n;i++){
		printf("%4d ",x[i]);
	}
	//printf("\n%d", sred);
	free(x);
	return 0;
}
