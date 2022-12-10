/* Assignment: 4
Author: Neoray Hagag, ID: 20809078
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 50
char* Newstring(char* str) {
	char* string = NULL, *temp = NULL;
	int size;
	int i = 0, j, numofnum, k = 0;
	string = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (string == NULL) {
		return NULL;
	}
	while (str[i] != '\0')
	{

		if (str[i] == '0') {
			i++;
			continue;
		}
		else if (str[i] >= '1' && str[i] <= '9') {
			numofnum = str[i] - '0';
			if (numofnum > 1) {
				size = strlen(string) + 1;
				temp = string;
				string = (char*)realloc(string, (size + numofnum) * sizeof(char));
				if (string == NULL) {
					free(temp);
					return NULL;
				}
			}

			for (j = 0; j < numofnum; j++, k++) {
				*(string + k) = str[i];
			}
			i++;
		}
		else if (str[i] == ' ')
		{
			while (str[i] == ' ') {
				if (!(str[i + 1] == ' ')) {
					*(string + k) = '-';
				}
				i++;
			}
			k++;

		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			while (str[i] >= 'a' && str[i] <= 'z')
			{
				if (!(str[i + 1] >= 'a' && str[i + 1] <= 'z'))
					*(string + k) = '*';
				i++;
			}
			k++;
		}
	}

	*(string + k) = '\0';
	return string;

 }
int main() {
	char str[MAX];
	printf("enter a string");
	gets_s(str ,MAX - 1);
	char* string = Newstring(str);
	if (string == NULL) {
		printf("error");
		exit(1);
	}
	puts(string);
	free(string);
	return 0;
}