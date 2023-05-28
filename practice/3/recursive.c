#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//count recursivly square
//yn - y next
float recursive(float x, float eps, int m, float y){
	float yn = y + 1.0/m*(x/pow(y, m-1) - y);
	if (fabs(yn - y) > eps){
		yn = y + 1.0/m*(x/pow(y, m-1) - y);
		// printf("%f  ", yn);
		return recursive(x, eps, m, yn);
	}else{
		return yn;
	}
	
	
}

float square(float x, float eps, int m, float y){
	float yn = y + 1.0/m*(x/pow(y, m-1) - y);
	//printf("%f\n", yn);
	while(fabs(yn - y) > eps){
		y = yn;
		yn = y + 1.0/m*(x/pow(y, m-1) - y);
//		printf("%f\n", yn);
	}
	return y;
}

int main(){
	printf("Enter eps: ");
	float eps;
	scanf("%f", &eps);
	
	printf("Enter x: ");
	float x;
	scanf("%f", &x);
	
	printf("Enter degree m: ");
	int m ;
	scanf("%d", &m);
	
	printf("Square(x, m): %f", square(x,eps, m, 0.1));
	printf("\nRecursve Square(x, m): %f", recursive(x,eps,m, 0.1));
	
	return 0;
}
