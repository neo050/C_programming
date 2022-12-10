/* Assignment: 5
Author: Neorar Hagag, ID: 208090738
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 20
#define MAX2 20
struct course
{
	char* name;
	int grade;
};

struct student
{
	char* name;
	int num_of_courses;
	struct course* arr;
};
struct student* initialize(int* psize) {
	printf("enter number of student\n");
	scanf_s("%d", psize);
	getchar();
	int i, j;
	char nameofstudent[MAX];
	/*char Nameofcourse[MAX];*/
	struct student* data = (struct student*)malloc((*psize) * sizeof(struct student));
	if (!data) {
		printf("\nno memory line 29\n");
		return NULL;
	}
	printf("\nEnter all data\n");
	for (i = 0; i < *psize; i++) {
		printf("\nEnter name of student: ");
		gets(nameofstudent);
		
		data[i].name = (char*)malloc((strlen(nameofstudent) + 1) * sizeof(char));
		if (!(*(data + i)).name)
		{
			printf("\nno memory line 40\n");
			
			return NULL;
		}
		strcpy((*(data + i)).name, nameofstudent);
		printf("\nEnter num of courses : ");
		scanf_s("%d", &(*(data + i)).num_of_courses);
		getchar();
		data[i].arr = (struct course*)malloc((data[i].num_of_courses) * sizeof(struct course));
		if (!(*(data + i)).arr) {
			printf("\nno memory line 58\n");
			return NULL;
		}
		for (j = 0; j < data[i].num_of_courses; j++) {
			printf(" \n enter name of cours: ");
			gets(nameofstudent);
			data[i].arr[j].name = (char*)malloc((strlen(nameofstudent) + 1) * sizeof(char));
			if (data[i].arr[j].name==NULL) {
				printf("\n no memory line 75\n");
				return NULL;
			}
			strcpy(data[i].arr[j].name, nameofstudent);
			printf("\n enter grade of student %d  in cours %d:  ", i, j);
			scanf_s("%d", &data[i].arr[j].grade);
			getchar();
		}
	}
	return data;
}

void print_student(struct student* arr, int size, char* name) {
	float avrege = 0;
	int i, isok = 1, j;
	for (i = 0; i < size && isok; i++) {
		if (strcmp(arr[i].name, name) == 0) {
			isok = 0;
			for (j = 0; j < arr[i].num_of_courses; j++) {
				printf(" \nname of cours: %d ,of student: %d is: %s and the grade of this cours: %d \n", j, i, arr[i].arr[j].name, arr[i].arr[j].grade);
				avrege = avrege + arr[i].arr[j].grade;
			}
			printf("the avrege of all grades = %f  \n", avrege / arr[i].num_of_courses);
		}
	}
	if (isok)
		printf("\nThere is no student by that name in our database");
}
void update(struct student* arr, int size, char* sname, char* cname, int grade) {
	int i, isok = 1, j;
	for (i = 0; i < size && isok; i++) {
		if (strcmp(arr[i].name, sname) == 0) {
			for (j = 0; j < arr[i].num_of_courses && isok; j++) {
				if (strcmp(arr[i].arr[j].name, cname) == 0) {
					arr[i].arr[j].grade = grade;
					isok = 0;
				}

			}
			if (isok) {
				arr[i].num_of_courses += 1;
				arr[i].arr = (struct course*)realloc((*(arr+i)).arr, (arr[i].num_of_courses) * sizeof(struct course));
				if (!arr[i].arr) {
					printf("\n no memory line 127\n");
					return;
				}
				arr[i].arr[arr[i].num_of_courses - 1].name = (char*)malloc((strlen(cname) + 1) * sizeof(char));
				strcpy((*(arr+i)).arr[arr[i].num_of_courses - 1].name, cname);
				arr[i].arr[arr[i].num_of_courses - 1].grade = grade;
				isok = 0;
			}

		}
	}
	if (isok)
		printf("\nThere is no student by that name in our database");


}
void common(struct student* arr, int size, char* s1, char* s2) {
	int i, isok = 1, j, s1n = -1, s2n = -1;
	for (i = 0; i < size && isok; i++) {
		if (strcmp(arr[i].name, s1) == 0) {
			s1n = i;
			isok = 0;
		}
	}
	isok = 1;
	for (i = 0; i < size && isok; i++) {
		if (strcmp(arr[i].name, s2) == 0) {
			s2n = i;
			isok = 0;
		}
	}
	if (s1n == -1 || s2n == -1) 
	{
		printf("\nThere is no student by that name in our database");
	}
	else
	{
		for (i = 0; i < arr[s2n].num_of_courses; i++) {
			for (j = 0; j < arr[s1n].num_of_courses; j++) {
				if (strcmp(arr[s1n].arr[j].name, arr[s2n].arr[i].name) == 0) {
					printf("The name of the joint course for the two students is: %s", arr[s1n].arr[j].name);
				}
			}
		}
	}
}
main() {
	int size, sgrade, i, j;
	char nameofstudent[MAX];
	char sname[MAX], scourse[MAX];
	struct student* data = initialize(&size);
	if (data == NULL) {
		printf("\n190\n");
		printf("Error");
		exit(1);
	}
	printf("\nHello Please enter the name of the student, the name of the course and the grade of the course: ");
	gets_s(nameofstudent, MAX - 1);
	gets_s(scourse, MAX - 1);
	scanf_s("%d", &sgrade);
	getchar();
	update(data, size, nameofstudent, scourse, sgrade);
	printf("\nHello Please enter the name of  student.");
	gets_s(nameofstudent, MAX - 1);
	print_student(data, size, nameofstudent);
	printf("\nHello Please enter the name of two students.");
	gets_s(nameofstudent, MAX - 1);
	gets_s(sname, MAX - 1);
	common(data, size, nameofstudent, sname);
	for (i = 0; i < size; i++) {
		for (j = 0; j < data[i].num_of_courses; j++) {
			free(data[i].arr[j].name);
		}
		free(data[i].arr);
		free(data[i].name);

	}
	free(data);

	return 0;

}