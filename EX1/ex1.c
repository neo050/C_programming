/*
Author: Nehorai Hagag, ID: 208090738
*/

#include<stdio.h>
int main() {
	char tav;
	printf("please insert a character!\n");
	tav = getchar();
	if (tav >= 'A' && tav <= 'Z')
		printf("tav=%c", tav+'a'-'A');
	else if (tav >= 'a' && tav <= 'z')
		printf("tav=%c", tav-'a'+'A');
	else
		printf("tav=%c", tav);
	return 0;
}
 