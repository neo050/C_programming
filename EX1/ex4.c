/*
Author: Nehorai Hagag, ID: 208090738
*/
#include<stdio.h>
int main() {
	int num;
	printf("enter number\n");
	scanf_s("%d", &num);
	if (num / 10000 != 0) {
		if (num / 100000 == 0)
			if (num % 10 % 2 == 0 && num / 10 % 10 % 2 == 1 && num / 100 % 10 % 2 == 0 && num / 1000 % 10 % 2 == 1 && num / 10000 % 2 == 0)
				printf("alternate");
			else if (num % 10 % 2 == 1 && num / 10 % 10 % 2 == 0 && num / 100 % 10 % 2 == 1 && num / 1000 % 10 % 2 == 0 && num / 10000 % 2 == 1)
				printf("alternate");
			else
				printf("not alternate ");

	}
	else
		printf(" invalid input");





	return 0;
}