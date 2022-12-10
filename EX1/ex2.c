/*
Author: Nehorai Hagag, ID: 208090738
*/

#include<stdio.h>
int main() {
	float num1, num2, Fractionnum1, Fractionnum2;
	printf("Please enter two real numbers\n");
	scanf_s("%f%f",&num1,&num2);
	Fractionnum1 = num1 - (int)num1;
	Fractionnum2= num2- (int)num2;
	if (Fractionnum1 < 0 || Fractionnum2 < 0)
		printf("Error");
	else if (Fractionnum2 > Fractionnum1)
		printf("%f", Fractionnum2);
	else if (Fractionnum2 < Fractionnum1)
		printf("%f", Fractionnum1);
	else
		printf("Both numbers have the same fractional value");

	return 0;
}