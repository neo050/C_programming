/* Assignment: 4
Author: Neoray Hagag, ID: 20809078
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 50
int* SymmetricDiff(int* one, int sizeOne, int* two, int sizeTwo, int* pNewSize) {

	int* Symmetric = NULL, i, j, isok = 1, caunt = 0, * temp = NULL;
	Symmetric = (int*)malloc((sizeOne + sizeTwo) * sizeof(int));
	if (Symmetric == NULL)
		return NULL;
	for (i = 0; i < sizeOne; i++) {
		isok = 1;
		for (j = 0; j < sizeTwo && isok; j++) {
			if (*(one + i) == *(two + j))
				isok = 0;
		}
		if (isok == 1) {
			*(Symmetric + caunt) = *(one + i);
			caunt++;
		}
	}	
	isok = 1;
	for (i = 0; i < sizeTwo; i++) {
		isok = 1;
		for (j = 0; j < sizeOne && isok; j++) {
			if (*(two + i) == *(one + j))
				isok = 0;
		}
		if (isok == 1) {
			*(Symmetric + caunt) = *(two + i);
			 caunt++;
		}
	}	
	temp = Symmetric;
	Symmetric = (int*)realloc(Symmetric,(caunt) * sizeof(int));
	if (Symmetric == NULL) {
		/*free(temp);*/
		return NULL;
	}
	*pNewSize = caunt;
	return Symmetric;

}
void getarr(int*arr,int size){
	int i;
	printf("\n");
	for (i = 0; i < size; i++) {
		scanf_s("%d",arr+i);
	}
}
void printarr(int* arr,int size) {
	int i;
	printf("\n");
	for (i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
}

int main() {
	int* one = NULL, sizeOne, * two = NULL, sizeTwo, * Symmetric, pNewSize;
	printf("enter two sizes \n");
	scanf_s("%d%d", &sizeOne,&sizeTwo);
	one = (int*)malloc((sizeOne) * sizeof(int));
	if (one == NULL)
		exit(1);
	two = (int*)malloc((sizeTwo) * sizeof(int));
	if (two == NULL)
		exit(1);
	printf("\nenter two arr \n");
	getarr(one, sizeOne);
	getarr(two, sizeTwo);
	Symmetric = SymmetricDiff(one, sizeOne, two, sizeTwo, &pNewSize);
	if (Symmetric == NULL)
		exit(1);
	if (pNewSize == 0) {
		printf("\nthe SymmetricDiff=0!\n");
	}
	else
		printarr(Symmetric, pNewSize);
	free(one);
	free(two);
	free(Symmetric);
	return 0;
}