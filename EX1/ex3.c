/*
Author: Nehorai Hagag, ID: 208090738
*/

#include<stdio.h>
int main() {
	int  numberofproducts;
	float  prices1, prices2, prices3;
	printf("Enter number of 1-3 products");
	scanf_s("%d",&numberofproducts);

	if (numberofproducts == 2) {
		printf("\nEnter 2  prices");
		printf("\n");
		scanf_s("%f", &prices1);
		printf("\n");
		scanf_s("%f", &prices2);
		printf("\n");
		if (prices1 > prices2)
			printf("Total price is:%.2f ", 0.7 * prices2 + prices1);
		else 
			printf("Total price is:%.2f ", 0.7 * prices1 + prices2);
	}
	if (numberofproducts == 3) {
		printf("\nEnter 3  prices");
		printf("\n");
		scanf_s("%f", &prices1);
		printf("\n");
		scanf_s("%f", &prices2);
		printf("\n");
		scanf_s("%f", &prices3);
		printf("\n");
		if (prices1 > prices2 && prices1 > prices3)
			if (prices2 > prices3)
				printf("Total price is:%.2f ", 0.5 * prices3 + 0.8 * prices2 + prices1);
			else
				printf("Total price is:%.2f ", 0.5 * prices2 + 0.8 * prices3 + prices1);
		else if (prices2 > prices1 && prices2 > prices3)
			if (prices1 > prices3)
				printf("Total price is:%.2f ", 0.5 * prices3 + 0.8 * prices1 + prices2);
			else
				printf("Total price is:%.2f ", 0.5 * prices1 + 0.8 * prices3 + prices2);
		else if (prices3 > prices1 && prices3 > prices2)
			if (prices1 > prices2)
				printf("Total price is:%.2f ", 0.5 * prices2 + 0.8 * prices1 + prices3);


			else
				printf("Total price is:%.2f ", 0.5 * prices1 + 0.8 * prices2 + prices3);
	}
	if (numberofproducts == 1)
		printf("\nEnter 1  prices");
		printf("\n");
		scanf_s("%f", &prices1);
		printf("\n");
		printf("Total price is:%.2f ", prices1);
	return 0;
}