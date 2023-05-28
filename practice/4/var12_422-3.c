#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float function1(float e){
	float next_x;
	float x = M_PI; //Значение подсчитано заранее
	while (1){
		next_x = x - (pow(x, 4)-0.48*pow(x, 3)-5.792*pow(x, 2)+0.486*x+4.792) / (4*pow(x, 3)-0.48*3*pow(x, 2)-5.792*2*x);
		if (fabs(pow(next_x, 4)-0.48*pow(next_x, 3)-5.792*pow(next_x, 2)+0.486*next_x+4.792) > e || fabs(next_x-x) > e)
			x = next_x;
		else
			break;
	}
	return next_x;
}


float function2(float e){
	float next_x;
	float x = M_PI; //Значение подсчитано заранее
	while (1){
		next_x = x - (0.1*sin(x)+pow(x, 3)-1) / (0.1*cos(x)+3*pow(x, 2));
		if (fabs(0.1*sin(next_x)+pow(next_x, 3)-1) > e || fabs(next_x-x) > e)
			x = next_x;
		else
			break;
	}
	return next_x;
}


float function3(float e){
	float next_x;
	float x = M_PI; //Значение подсчитано заранее
	while (1){
		next_x = x - (0.1*exp(x)-pow(sin(x), 2)+0.5) / (0.1*exp(x)-2*sin(x)*cos(x));
		if (fabs(0.1*exp(next_x)-pow(sin(next_x), 2)+0.5) > e || fabs(next_x-x) > e)
			x = next_x;
		else
			break;
	}
	return next_x;
}


int main(int argc, char *argv[]) {
    system("chcp 1251");
    int f;
    float e, x;
    printf("Введите точность вычислений: ");
    scanf("%f", &e);
    printf("Выберете функцию (1, 2, 3): ");
    scanf("%d", &f);
    if (f == 1)
    	x = function1(e);
    if (f == 2)
    	x = function2(e);
    else
    	x = function3(e);
    printf("Полученный ответ: %f\n", x);
    system("PAUSE");
}
