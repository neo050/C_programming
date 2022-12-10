/*
Author: Neoray Hahah , ID: 208090738
*/
#include<stdio.h>
void max1_2_2()
{
	printf("enter numbers end num < 0 to end\n ");
	float num, first, second, third, temp;
	scanf_s("%f", &num);
	first = second = third = num;
	temp = num;
	while (num > 0)
	{
		if (num > first)
		{
			third = second = first;
			first = num;
		}
		else if (num < first)
		{
			if ((first == second) && (first == third))
				third = second = num;
			else if (num > second)
				third = second = num;
		}

		scanf_s("%f", &num);
	}
	printf("\nfirst=%f\nsecond =%f\nthird =%f\n", first, second, third);
}
void Freak_numbers(long Num)
{
	int i, j = 0;
	long temp = Num;
	if (Num == 2)
		printf("2");
	for (i = 2; i < Num; i++)
	{
		for (; temp % i == 0; temp /= i)
		{
			printf("%ld*", i);
			j++;
		}

		if (temp < i)
			break;
	}
	if (j == 0)
		printf("%ld", Num);
	printf("\n");
}
int IDproper(long Num)
{
	int  help;
	long num = Num;
	int i, sum = 0, Checkdigit, temp;
	if ((Num > 9999999 && Num < 100000000) || (Num > 99999999 && Num < 1000000000))
	{
		Checkdigit = num % 10;
		num /= 10;
		if (Num > 9999999 && Num < 100000000)
		{
			for (i = 10; num > 0; num /= 100)
			{
				if (num / 10 == 0) {
					sum = sum + num % 10;
					break;
				}
				help = num / i % i * 2;
				sum = num % i + sum;
				if (help >= 10)
					sum = sum + help % 10 + help / 10;
				else
					sum = sum + help;
			}
			if (sum % 10 == 0 && Checkdigit == 0)
				return 1;
			else if (sum % 10 != 0) {
				temp = sum;
				while (temp % 10 != 0)
					temp++;
				if (temp - sum == Checkdigit)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else if (Num > 99999999 && Num < 1000000000)
		{

			for (i = 10; num > 0; num /= 100)
			{
				help = num % i * 2;
				sum = num / i % i + sum;
				if (help >= 10)
					sum = sum + help % 10 + help / 10;
				else
					sum = sum + help;
			}
			if (sum % 10 == 0 && Checkdigit == 0)
				return 1;
			else if (sum % 10 != 0) {
				temp = sum;
				while (temp % 10 != 0)
					temp++;
				if (temp - sum == Checkdigit)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		
			
			
		}
	}
	else
		return 0;
}
void diamond(int Num) {
	int i, j, k, num = Num, g = 0, l;
	l = (num - 1) * 2;
	for (i = 1, k = num - 1; i <= num; i++, k--) {
		for (j = 1; j <= k; j++)
			printf(" ");
		printf("/");
		for (; g <= (num - 1) * 2; ) {
			for (j = 0; j < g; j++)
				printf(" ");
			printf("\\");
			printf("\n");
			g += 2;
			break;
		}
	}
	for (i = 1, k = 0; i <= num; i++, k++) {
		for (j = 1; j <= k; j++)
			printf(" ");
		printf("\\");
		for (; l <= (num - 1) * 2; ) {
			for (j = 0; j < l; j++)
				printf(" ");
			printf("/");
			printf("\n");
			l -= 2;
			break;
		}
	}
}
void Composenums(int num_a, int num_b)
{
	long newnum = num_a;
	int  num2 = num_b, j = 1, f, i;
	while (num_b - num_b % 10 != 0) {
		while (num2 / 10 > 10) {
			num2 /= 10;
			j++;
		}
		for (f = 1, i = 1; i <= j; i++) {
			f = 10 * f;
		}
		j = 1;
		num_b = num_b - f * (num2 / 10);
		newnum = newnum * 10 + num2 / 10;
		num2 = num_b;
	}
	newnum = newnum * 10 + num2;
	printf("\n%ld\n", newnum);
}
int main() {
	int num1_6, diamond1,num1,num2;
	long integer,id;
	do {
		printf("1 – Third\n2 – Primes\n3 – ID\n4 – Diamond\n5 – Compose\n6 – Quit\nenter a number\n");
		scanf_s("%d", &num1_6);
		switch (num1_6)
		{
		case 1:
			max1_2_2();
			break;
		case 2:
			printf("enter an integer\n");
			scanf_s("%d", &integer);
			Freak_numbers(integer);
			break;
		case 3:
			printf("enter an ID\n");
			scanf_s("%ld", &id);
			if(1== IDproper(id))
				printf("normal ID\n");
			else
				printf("ont a normal ID\n");
			break;
		case 4:
			printf("enter number 1-10\n");
			scanf_s("%d", &diamond1);
			if (1 <= diamond1 && diamond1 <= 10)
				diamond(diamond1);
			else
				printf("This number does not meet the standard Please select a number between 1-10\n");
			break;
		case 5:
			printf("enter two integer\n");
			scanf_s("%d%d", &num1, &num2);
			Composenums(num1,num2);
			break;
		default:
			if(!(num1_6>=1&& num1_6 <= 6))
				printf("This number does not meet the standard Please select a number between 1-6\n");
			break;
		}


	} while (num1_6 != 6);
	
	return 0;
}