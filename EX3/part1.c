/*Assignment: 3
Author:Neoray hagag, ID: 208090738*/
#include<stdio.h>
#include<string.h>
#define N 10
#define M 5
void polynom(int One[], int size1, int Two[], int size2)
{
	int i, j, I = 0;
	long sum, temp;
	for (i = size1 - 1; i >= 0; i--)
	{
		printf("%d*X^%d+", One[i], i);
	}
	for (i = 0; i < size2; i++)
	{
		if (Two[i] == 0) {
			printf("\nThe value of the polynom for x=%d is: %d\n", Two[i], One[0]);
			continue;
		}
		temp = 0;

		for (I = 0; I < size1; I++)
		{
			sum = 1;
			j = I;
			do
			{
				if (I != 0)
					sum = sum * Two[i];
				else
					sum = One[0];


				j--;
			}

			while (j > 0);
			if (j >= 0)
				sum = sum * One[I];
			temp = temp + sum;
		}
		printf("\nThe value of the polynom for x=%d is: %ld\n", Two[i], temp);
	}
}
int subarray(int arr1[], int size1, int arr2[], int size2)
{
	int i, j, index = 0;
	int index2 = 0;
	if (size1 < size2)
		return -1;
	for (i = 0, j = 0, index2 = i; i < size1; i++)
	{
		if (arr1[i] != arr2[j])
		{
			index2 = i;
			index = 0;
		}
		else if (arr1[i] == arr2[j])
		{
			index++;
			j++;
		}
		if (index == size2)
		{
			if (index2 > 0)
				return index2 + 1;
			else
				return index2;
		}
	}

	if (index != size2)
		return -1;
}
int Longestseries(int arr1[], int size1)
{
	int i, caunt = 0, index = 1, max = 1, I = 0, j;
	for (i = 0; i < size1 - 1; i++)
	{
		if (arr1[i] < arr1[i + 1]) {
			index++;
		}
		if (arr1[i] > arr1[i + 1] && index >= 2) {
			caunt++;
			if (max < index) {
				max = index;
				I = i;
			}
			index = 1;
		}
	}
	printf("\nLongest series:");
	for (i = I - (max - 1), j = max; j > 0; i++, j--)
	{
		printf("%d ", arr1[i]);
	}
	return caunt;
}
int main()
{
	int One[N], Two[M], i, YourChoice, index;
	printf("enter 10 numbers\n");
	for (i = 0; i < N; i++) {
		scanf_s("%d",&One[i]);
	}
	printf("\nenter 5 numbers\n");
	for (i = 0; i < M; i++) {
		scanf_s("%d", &Two[i]);
	}
	
	do {
		printf("\nPlease enter your choice:\n1-polynom\n2-sub array\n3-series\nenter 0 to stop\n");
		scanf_s("%d", &YourChoice);
		switch (YourChoice)
		{
		case 1:
			polynom(One, N, Two, M);
			break;
		case 2:
			subarray(One, N, Two, M);
			index = subarray(One, N, Two, M);
			if (index == -1)
				printf("\nThe sub-array is not contained in the array\n.");
			else
				printf("\nThe sub-array starts at index %d\n", index);
			break;
		case 3:
			printf("\nThe amount of series that go up:%d\n", Longestseries(One, N));
			break;
		default:
			if (YourChoice!=0 && !(YourChoice >= 1 && YourChoice <= 3))
				printf("\nThis number does not meet the standard Please select a number between 1-3\n");
			break;
		}

	} 	while (YourChoice>0);
	
	
	return 0;

}
