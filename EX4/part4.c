/* Assignment: 4
Author: Neoray Hagag, ID: 20809078
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 50
void wordFrequency(char** words, int countWords) {
	int i,I, j, caunt = 1,isok;
	for (i = 0; i < countWords; i++) {
		caunt = 1;
		isok = 1;
		for (I = i - 1; I >= 0 && i != 0; I--) {

			if (strcmp(words[i], words[I]) == 0) {
				/*i++;*/
				isok = 0;
				break;
			}
		}
		for (j = i+ 1; j < countWords&&isok ;j++) {

			if (strcmp(words[i], words[j]) == 0)
				caunt++;
			/*continue;*/
		}
		if(isok)
			printf("\n%s:%d\n", words[i],caunt);
		
	}

}
char** textPreprocessing(char** text, int* countWords, char** stopwords, int countStopwords) {
	int i, j,isok=1,k=0,J;
	char** str = (char**)malloc(*countWords * sizeof(char*));
	for (i = 0; i < *countWords; i++) {
		str[i] = (char*)malloc(11 * sizeof(char));
		if (str[i] == NULL) {
			for (j = 0; j < i; j++) {
				free(str[i]);
			}
			free(str);
			return NULL;
		}
	}
	/*if (str == NULL)
		return NULL;*/
	for (i = 0; i < *countWords; i++) {
		for (j = 0; text[i][j] != '\0'; j++)
			if (text[i][j] >= 'A' && text[i][j] <= 'Z') {
				text[i][j] = text[i][j] + ('m' - 'M');
			}
	}
	for (i = 0; i < countStopwords; i++) {
		for (j = 0; stopwords[i][j] != '\0'; j++)
			if (stopwords[i][j] >= 'A' && stopwords[i][j] <= 'Z') {
				stopwords[i][j] = stopwords[i][j] + ('m' - 'M');
			}
	}
	for (i = 0; i < *countWords; i++) {
		isok = 1;
		for (j = 0; text[i][j] != '\0'&&isok; j++) {
			if (text[i][j] >= '0' && text[i][j] <= '9') {
				isok = 0;
			}
			else
			{
				for (J = 0; J < countStopwords&&isok; J++) {
					if (strcmp(text[i], stopwords[J]) == 0)
							isok = 0;
				}
				
			}
			
		}
	
		if (isok) {
			strcpy(str[k], text[i]);
			/*str[k] = text[i];*/
			k++;
		}
	}
	for (i = 0; i < k; i++) {
		str[i] = (char*)realloc(str[i], (strlen(str[i])+1) * sizeof(char));
	}
	/*str = (char**)realloc(str,(k)* sizeof(char*));
	if (str == NULL)
		printf("error88");
		return NULL;*/
	for (j = 0; j < *countWords; j++) {
		free(text[j]);
	}
	free(text);
	for (j = 0; j < countStopwords; j++) {
		free(stopwords[j]);
	}
	free(stopwords);
	*countWords = k;
    return str;
}

char** buildwords(char** words,int countWords) {
	int i, j;
	char str[MAX];
	words = (char**)malloc(countWords * sizeof(char*));
	if (words == NULL)
		return NULL;
	printf("\nenter words\n");
	for (i = 0; i < countWords; i++) {
		scanf("%s", str);
		printf("\n");
		words[i] = (char*)malloc((strlen(str) + 1) * sizeof(char));
		if (words[i] == NULL) {
			for (j = 0; j < i; j++) {
				free(words[i]);
			}
			free(words);
			return NULL;
		}
		strcpy(words[i], str);

	}
	return words;

}
	
	

int main() {
	char** words = NULL, **text=NULL,** stopWords=NULL;
	int countWords, i, countWords2, countStopWords;
	printf("enter number of words\n");
	scanf_s("%d", &countWords);
	if (countWords <= 0) {
		printf("enter number! > 0 ! of words\n");
		scanf_s("%d", &countWords);
	}
	words = buildwords(words, countWords);
	if (words == NULL) {
		printf("error");
		exit(1);
	}
	wordFrequency(words,countWords);
	printf("\nenter number of words for the ponc text\n");
	scanf_s("%d", &countWords2);
	text= buildwords(text, countWords2);
	if (text == NULL) {
		printf("error");
		exit(1);
	}
	printf("enter number of stopWords for the ponc text\n");
	scanf_s("%d", &countStopWords);
	stopWords = buildwords(stopWords, countStopWords);
	text = textPreprocessing(text, &countWords2, stopWords, countStopWords);
	if (text == NULL) {
		printf("error");
		exit(1);
	}
	wordFrequency(text, countWords2);

	for (i= 0; i <countWords; i++) {
		free(words[i]);
	}
	free(words);
	for (i = 0; i < countWords2; i++) {
		free(text[i]);
	}
	free(text);
	return 0;
}



