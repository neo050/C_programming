/*Assignment: 3
Author:Neoray hagag, ID: 208090738*/
#include<stdio.h>
#include<string.h>
#define  SIZE_ROW 5
#define SIZE_COL 8
#define SIZESquares 4
int Maxsymmetricsubmatrix(int arr[][SIZE_COL])
{
	int i, j, row, col, maxLen = 0, isOk = 1, rowMaxLen = 0, colMaxLen = 0;

	for (row = 0; row < SIZE_ROW; row++)
	{
		for (col = 0; col < SIZE_COL; col++)
		{
			isOk = 1;
			for (i = 1; i + row < SIZE_ROW && i + col < SIZE_COL && isOk; i++)
			{
				for (j = 0; j < i && isOk; j++)
				{
					isOk = (arr[row + i][col + j] == arr[row + j][col + i]);
				}
			}
			if (isOk == 0)
			{
				i--;
			}
			if (i > maxLen)
			{
				maxLen = i;
				rowMaxLen = row;
				colMaxLen = col;
			}
		}
	}
	printf("The Max symmetric sub-matrix starts at indexes [%d][%d] and its size is: %d", rowMaxLen, colMaxLen, maxLen);
}
void Numberofmultiplesanddivisors(int arr[SIZESquares][SIZESquares], int I, int J)
{
	int Numberofmultiples = 0, Numberofdivisors = 0, i, j;
	if (!(I >= 0 && I <= 3) || !(J >= 0 && J <= 3)) {
		printf("Invalid column index, try again!");
		return;
	}
	for (i = 0; i < SIZESquares; i++) {
		for (j = 0; j < SIZESquares; j++) {

			if (arr[i][j] % arr[I][J] == 0)
				Numberofmultiples++;
			if (arr[I][J] % arr[i][j] == 0)
				Numberofdivisors++;
		}
	}
	printf("\nNumber of multiples:%d\nNumber of divisors:%d", Numberofmultiples, Numberofdivisors);
	
}
int main() {
	int submatrix[SIZE_ROW][SIZE_COL],divisorsmultiples[SIZESquares][SIZESquares], i,j,YourChoice,index,Row, Column;
	printf("\nHello dear user, please insert a 5 by 8 square matrix into the system\n");
	for (i = 0; i < SIZE_ROW; i++) {
		for (j = 0; j < SIZE_COL; j++)
			scanf_s("%d", &submatrix[i][j]);
	}
	printf("\nHello again dear user, please insert a 4 by 4 square matrix into the system\n");
	for (i = 0; i < SIZESquares; i++) {
		for (j = 0; j < SIZESquares; j++)
			scanf_s("%d", &divisorsmultiples[i][j]);
	}

	do {
		printf("\nPlease enter your choice:\n1-divisorsmultiples\n2-submatrix\nenter 0 to stop\n");
		scanf_s("%d",&YourChoice);
		switch (YourChoice)
		{
		case 2:
			Maxsymmetricsubmatrix(submatrix);
			break;
		case 1:
			printf("\nPlease enter a row  number that have value between zero and three\n");
			scanf_s("%d", &Row);
			printf(" \nPlease enter a column  number that have value between zero and three\n");
			scanf_s("%d", &Column);
			Numberofmultiplesanddivisors(divisorsmultiples,Row,Column);
			break;
		
		default:
			if (YourChoice != 0 && !(YourChoice >= 1 && YourChoice <= 2))
				printf("\nThis number does not meet the standard Please select a number between 1-2\n");
			break;
		}

	} while (YourChoice != 0);


	return 0;
}
