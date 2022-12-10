/*
Author: Nehorai Hagag, ID: 208090738
*/
#include<stdio.h>
int main() {
	int num1, num2, num3, num4, num5, Evennumber=0, Oddnumber=0;
	float Oddaverage, Evenaverage, even = 0.0, odd = 0.0;
	printf("enter 5 number\n");
	scanf_s("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);
	if (num1 % 2 == 0) {
		even++;
		Evennumber = num1;
	}
	else {
		odd++;
		Oddnumber = num1;
	}
	
	if (num2 % 2 == 0) {
		even++;
		Evennumber = Evennumber+ num2;
	}
	else {
		odd++;
		Oddnumber = Oddnumber + num2;
	}
	if (num3 % 2 == 0) {
		even++;
		Evennumber = Evennumber + num3;
	}
	else {
		odd++;
		Oddnumber = Oddnumber + num3;
	}
	if (num4 % 2 == 0) {
		even++;
		Evennumber = Evennumber + num4;
	}
	else {
		odd++;
		Oddnumber = Oddnumber + num4;
	}
	if (num5 % 2 == 0) {
		even++;
		Evennumber = Evennumber + num5;
	}
	else {
		odd++;
		Oddnumber = Oddnumber + num5;
	}
	Oddaverage = Oddnumber / odd;
	Evenaverage = Evennumber / even;
	if (odd == 0)
		printf("No Odd number numbers\nEvenaverage=%f", Evenaverage);

	else if (even == 0)
		printf("No even number numbers\nOddaverage=%f", Oddaverage);
	else
		printf("Oddaverage=%f\nEvenaverage=%f", Oddaverage, Evenaverage);

	return 0;
}