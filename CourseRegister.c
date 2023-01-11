#include <stdio.h>
int main()
{
	char id[7], advisor[50];
	char name[50];
	int subject_qty, i, total_credit = 0;
	printf("Enter name:\n");
	scanf(" %[^\n]s", name);
	printf("Enter student ID:\n");
	scanf(" %s", id);
	printf("Enter academic advisor's name:\n");
	scanf(" %[^\n]s", advisor);
	printf("Enter number of subjects to register:\n");
	scanf(" %i", &subject_qty);
	char subject[subject_qty][50], code[subject_qty][10];
	int credit[subject_qty];
	for (i = 0; i < subject_qty; i++)
	{
		printf("Enter subject to be registered:\n");
		scanf(" %[^\n]s", subject[i]);
		printf("Enter subject code:\n");
		scanf(" %[^\n]s", code[i]);
		printf("Enter credit hour:\n");
		scanf("%i", &credit[i]);
	}
	for (i = 0; i < subject_qty; i++)
	{
		total_credit = total_credit + credit[i];
	}
	if (total_credit > 18)
	{
		printf("Invalid Registration");
	}
	else
	{
		printf("\t\tUniversity of Pahang, Malaysia\n");
		printf("\t\t  Subjects Registration Form\n");
		printf("   ========================================================\n");
		printf("Name: %s\n", name);
		printf("Student ID: %s\n", id);
		printf("Total Subjects: %i\n", subject_qty);
		printf("-----------------------------------------------------------\n");
		printf("Subject Code\t\tCredit\t\tSubject Name\n");
		for (i = 0; i < subject_qty; i++)
		{
			printf("%s     \t\t%i     \t\t%s\n", code[i], credit[i], subject[i]);
		}
		printf("-----------------------------------------------------------\n");
		printf("Total Credits:\t\t%i\n", total_credit);
		printf("Academic Advisor = %s\n", advisor);
	}
	return 0;
}