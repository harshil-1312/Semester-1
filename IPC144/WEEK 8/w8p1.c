
//***************************************************************************** 
// Full Name  : Harshil Prajapati
//student ID#: 175255215
//Email       : hprajapati8@myseneca.ca
//Section    :IPC144ZRA.5605.2227
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation
//*****************************************************************************




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* num)
{
	int i = 0;
	while (i < 1)
	{
		scanf("%d", &i);
		if (i < 1)
			printf("ERROR: Enter a positive value: ");
	} 
	if (num != 0)
		*num = i;
	return i;
}
double getDoublePositive(double* num) 
{
	double i = 0;
	while (i < 1)
     {
		scanf("%lf", &i);
		if (i < 1)

			printf("ERROR: Enter a positive value: ");
	}
	if (num != 0)

		*num = i;
	return i;
}
void openingMessage(const int num_products) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product ", num_products);
	printf("data for analysis.\n");
	printf("NOTE: A 'serving' is %dg\n", per_serve);
}
void  getCatFoodInfo(const int i, struct CatFoodInfo* food)
 {
	printf("\nCat Food Product #%d\n", i + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food->sku_num);
	printf("PRICE         : $");
	getDoublePositive(&food->value);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food->mass);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food->cal);

}
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(const int sku_num, const double* value, const int cal, const double* mass)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_num, *value, *mass, cal);
}

void start()
{
	struct CatFoodInfo food[MAX_PRODUCT] = {{0}};
	int i;
	openingMessage(MAX_PRODUCT);
	for (i = 0; i < MAX_PRODUCT; i++)
		 getCatFoodInfo(i, &food[i]);
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
		displayCatFoodData(food[i].sku_num, &food[i].value, food[i].cal, &food[i].mass);
}