/* Assignment: 4
Author: Neoray Hagag, ID: 20809078
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 50
int** BuildMatrix(int* pRow, int* pColumn);
void PrintMatrix(int** matrix, int row, int column);
int** TransposeMatrix(int** matrix, int row, int col);
int main() {
	int**arr,**trans, row, col;
	arr=BuildMatrix(&row, &col);
	if (arr == NULL) {
		printf("error");
		exit(1);
	}
	printf("\n");
	PrintMatrix(arr, row, col);
	trans = TransposeMatrix(arr, row, col);
	if (trans == NULL) {
		printf("error");
		exit(1);
	}
	printf("\n");
	PrintMatrix(trans, col, row);
	return 0;
}
int** BuildMatrix(int* pRow, int* pColumn) {
	int** matrix = NULL, i,j;

	printf("enter numbers of row and Col\n ");
	scanf_s("%d%d", pRow, pColumn);
	matrix = (int**)malloc(*pRow * sizeof(int*));
	if (matrix == NULL)
		return NULL;
	for (i = 0; i < *pColumn; i++) {
		matrix[i] = (int*)malloc(*pColumn * sizeof(int));
		if (matrix[i] == NULL) {
			for (j = 0; j < i; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}

	printf("enter values");
	for (i = 0; i < *pRow; i++) {
		for (j = 0; j < *pColumn; j++)
			scanf_s("%d", *(matrix + i)+j);

	}

	return matrix;
 }
void PrintMatrix(int** matrix, int row, int column) {
	int i,j;
	for (i = 0; i < row; i++) {
		for (j = 0; j <column; j++)
			printf("%d ", *(*(matrix + i) + j));

		printf("\n");
	}
}   
int** TransposeMatrix(int** matrix, int row, int col) {
	int** transpose = NULL,i,j;
	transpose = (int**)malloc(col * sizeof(int*));
	if (transpose == NULL)
		return NULL;
	for (i = 0; i < col; i++) {
		transpose[i] = (int*)malloc(row * sizeof(int));
		if (transpose[i] == NULL) {
			for (j = 0; j < i; j++)
				free(transpose[j]);
			free(transpose);
			return NULL;
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}
	return transpose;
}