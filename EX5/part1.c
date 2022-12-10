/* Assignment: 5
Author: Neorar Hagag, ID: 208090738
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 7
#define MAX2 11

int longnum(long num) {
	if (num == 0)
		return 0;
	else if ((num % 10 % 2) == 1)
		return 1 + longnum(num / 10);
	else
		return 0+ longnum(num / 10);

}
int dividedbynum(int arr[], int size, int num) {
	if (size > 0) {
		if (arr[0] % num == 0)
			return 1 + dividedbynum(arr + 1, size - 1, num);
		else
			return 0 + dividedbynum(arr + 1, size - 1, num);
	}
	else
		return 0;
}
int equalityincharacters(char arr[], int size, char arr2[], int size2) {
	if (size == 0&& size2 == 0)
		return 1;
	if (((arr[0] >= 'A' && arr[0] <= 'Z') || (arr[0] >= 'a' && arr[0] <= 'z')) && ((arr2[0] >= 'A' && arr2[0] <= 'Z') || (arr2[0] >= 'a' && arr2[0] <= 'z'))) {
		if ((arr[0] - arr2[0]) == 32 || (arr[0] - arr2[0]) == -32)
			return equalityincharacters(arr + 1, size - 1, arr2 + 1, size2 - 1);
		if (arr[0] == arr2[0])
			return equalityincharacters(arr + 1, size - 1, arr2 + 1, size2 - 1);
		return 0;
	}
	if (arr[0] == arr2[0]) {
			return equalityincharacters(arr + 1, size - 1, arr2 + 1, size2 - 1);
		
	}
	return 0;
}
int main() {
	long num=6778987;
	char str[MAX2] = { "AbC123$dEfG" }, str2[MAX2] = { "abC123$DEfg" };
	int arr[MAX] = { 926,560,36,90,681,405,707 }, num1 = 10;
	int x = longnum(num);
	printf("num of not even = %d\n ", x);
	printf("num of divided by the num %d = %d\n ",num1, dividedbynum(arr, MAX, num1));
	printf("1=equality\n0=unequality\nanser=%d", equalityincharacters(str, MAX2, str2, MAX2));

}
