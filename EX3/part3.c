/*Assignment: 3
Author:Neoray hagag, ID: 208090738*/
#include<stdio.h>
#include<string.h>
#define SIZE1 80
#define SIZE2 80
void expression(char arr[])
{
	char operator;
	long number;
	int decimalDigits, decimalLocation, minDecimalDigits = 99;
	double value[2];
	int i = 0, j, numIndex;
	for (numIndex = 0; numIndex < 2; numIndex++)
	{
		decimalLocation = -1;
		number = 0;
		for (; arr[i] != '\0' && arr[i] != ' ' && arr[i] != '\n'; i++)
		{
			if (arr[i] == '.')
			{
				if (decimalLocation != -1)
				{
					printf("Multiple decimal points");
					return;
				}
				decimalLocation = i;
			}
			else {
				if (arr[i] >= '0' && arr[i] <= '9')
				{
					number = number * 10 + (arr[i] - '0');
				}
				else {
					printf("Invalid data");
					return;
				}
			}
		}
		if (decimalLocation == -1)
		{
			decimalDigits = 0;
		}
		else {
			decimalDigits = i - decimalLocation - 1;
		}
		value[numIndex] = number;
		for (j = 0; j < decimalDigits; j++)
		{
			value[numIndex] /= 10.0;
		}
		if (numIndex == 0)
		{
			++i;
			operator = arr[i];
			i += 2;
			minDecimalDigits = decimalDigits;
		}
		else {
			if (minDecimalDigits == 0)
			{
				minDecimalDigits = decimalDigits;
			}
			else {
				if (decimalDigits > 0 && decimalDigits < minDecimalDigits)
				{
					minDecimalDigits = decimalDigits;
				}
			}
		}
		
	}
	double result = 0.0;

	switch (operator)
	{
	case '+':
		result = value[0] + value[1];
		break;
	case '-':
		result = value[0] - value[1];
		break;
	case '*':
		result = value[0] * value[1];
		break;
	case '/':
		result = value[0] / value[1];
		break;
	default:
		printf("Invalid");
		break;
	}
	
	int power = 1;
	for (j = 0; j < minDecimalDigits; j++)
	{
		power *= 10;
	}
	int leftSide = (int)result;
	number = (int)(result * power);
	int rightSide = number % power;
	printf("Final result: %d", leftSide);
	if (minDecimalDigits > 0)
	{
		printf(".%d", rightSide);
	}
}
void Encryptedencoding(char Sss[]) {
	int i = 0, caunt = 1, caunt2;
	while (Sss[i] != '\0')
	{
		while (Sss[i] != ' ' && Sss[i] != '\0') {
			caunt2 = caunt;
			while (caunt2 > 0) {
				if (Sss[i] >= '0' && Sss[i] <= '9')
					Sss[i] = '.';
				else
					Sss[i] = Sss[i] - ('B' - 'A');

				caunt2--;
			}
			i++;
			caunt++;
		}
		if (Sss[i] == ' ') {
			caunt = 1;
			i++;

		}
	}
	puts(Sss);
}
int main()
{
	char expressionmat[SIZE1];
	printf("enter a mat expression\n ");
	gets_s(expressionmat, SIZE1 - 1);
	expression(expressionmat);
	char secret[SIZE1];
	printf("\nHello dear user Tell me your secret,LOL.\n");
	gets_s(secret, SIZE1 - 1);
	Encryptedencoding(secret);
	return 0;
}
