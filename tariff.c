#include <stdio.h>

int main()
{
	int building, exit;
	float usage, billB, billA, total;
	do
	{
		printf("Building type: ");
		scanf("%i", &building);
		printf("Usage watt: ");
		scanf("%f", &usage);
		switch (building)
		{
		case 1000:
			billB = usage * 23.56;
			break;

		case 1001:
			billB = usage * 17.54;
			break;

		case 1002:
			billB = usage * 40.78;
			break;

		case 1003:
			billB = usage * 50.00;
			break;

		case 1004:
			billB = usage * 60.00;
			break;

		default:
			printf("Invalid building type.\n");
			break;
		}
		if (usage >= 10.0 && usage <= 29.0)
		{
			billA = billB * 0.9;
		}
		else if (usage >= 30.0 && usage <= 49.0)
		{
			billA = billB * 0.8;
		}
		else
		{
			billA = billB * 0.7;
		}
		total += billA;
		printf("Bill for this month:\nRM%.2f\n", billB);
		printf("Bill after discount:\nRM%.2f\n", billA);
		printf("Exit?(0 for yes / 1 for no)\n=");
		scanf("%i", &exit);
	} while (exit == 1);
	printf("Total payment:\nRM%.2f\n", total);
	return 0;
}