//********* 
// Full Name  : Harshil Prajapati
//student ID#: 175255215
//Email       : hprajapati8@myseneca.ca
//Section    :IPC144ZRA.5605.2227
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation
//*********




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w8p2.h"
//1

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

//2

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

//3

void openingMessage(const int num_products) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product ", num_products);
	printf("data for analysis.\n");
	printf("NOTE: A 'serving' is %dg\n", per_serve);
}

//4

void getCatFoodInfo(const int i, struct CatFoodInfo* food)
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

//5

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

//6

void displayCatFoodData(const int sku_num, const double* value, const int cal, const double* mass)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_num, *value, *mass, cal);
}


//8

double convertLbsKg(const double* lbs_weight, double* kg)
{
	double n;
	n = *lbs_weight / KG_IN_LBS;
	if (kg != 0)
	{
		*kg = n;

	}

	return n;
}

//9 

int convertLbsG(const double* lbs_weight, int* gm)
{
	int n;
	n = convertLbsKg(lbs_weight, 0) * 1000;
	if (gm != 0)
	{
		*gm = n;
	}
	return n;
}

//10

void convertLbs(const double* lbs_to_kg, double* kg, int* gm)
{
	convertLbsKg(lbs_to_kg, kg);
	convertLbsG(lbs_to_kg, gm);
}

//11

double calculateServings(const int mass_volume, const int total_sum, double* result)
{
	double n;

	n = (double)total_sum/ (double)mass_volume;
	if (result != 0)
	{
		*result = n;
	}
	return n;
}

//12

double calculateCostPerServing(const double* product_rate, const double* result, double* total_Cost)

{
	double n = 0;

	n = *product_rate / *result;

	if (total_Cost != NULL)
	{
		*total_Cost = n;
	}

	return n;
}

//13

double calculateCostPerCal(const double* cost_price, const double* calories, double* Cost_per_Calories)
{
	double n = 0;

	n = *cost_price / *calories;


	if (Cost_per_Calories != 0)
	{
		*Cost_per_Calories = n;
	}


	return n;
}

//14


struct ReportData calculateReportData(const struct CatFoodInfo detail_food_calorie)
{
	struct ReportData reslut;
	double calorie;


	// For SKU, RATE, Weight and Calories
	
	reslut.sku_num = detail_food_calorie.sku_num;

	reslut.cost = detail_food_calorie.value;

	reslut.mass = detail_food_calorie.mass;

	reslut.cal = detail_food_calorie.cal;

	// For kg and g

	reslut.kg = convertLbsKg(&detail_food_calorie.mass, &reslut.kg);

	reslut.gm = convertLbsG(&detail_food_calorie.mass, &reslut.gm);

	reslut.Sum_total = calculateServings(per_serve, reslut.gm, &reslut.Sum_total);

	reslut.per_weight = calculateCostPerServing(&reslut.cost,&reslut.Sum_total, &reslut.per_weight);

	calorie = reslut.cal * reslut.Sum_total;

	reslut.per_cal = calculateCostPerCal(&reslut.cost, &calorie, &reslut.per_cal);

	return reslut;
}

//15

void displayReportHeader(void)
{
	printf("\n"
	"Analysis Report (Note: Serving = %dg)\n", per_serve);
	printf("---------------\n"
	"SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n"
	"------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

//16

void displayReportData(const struct ReportData result, const int least_value)
{
	printf
        ("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		result.sku_num, result.cost, result.mass, result.kg, result.gm,
		result.cal, result.Sum_total, result.per_weight,result.per_cal);
}

//17

void displayFinalAnalysis(const struct CatFoodInfo cheap) 
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cheap.sku_num, cheap.value);
	printf("\n");
	printf("Happy shopping!\n");
	printf("\n");
}

// 7

void start(void)
{
	struct CatFoodInfo catFoodDetail[MAX_PRODUCT];
	int result = 0, cheap_product = 0; 

	int n;

	openingMessage(MAX_PRODUCT);

	for (result = 0; result < MAX_PRODUCT; result++)
	{
 getCatFoodInfo(result, &catFoodDetail[result]);
	}

	displayCatFoodHeader();

	for (result = 0; result < MAX_PRODUCT; result++)
	{
		displayCatFoodData(catFoodDetail[result].sku_num, &catFoodDetail[result].value,
			catFoodDetail[result].cal, &catFoodDetail[result].mass);
	}

	struct ReportData reportArray[MAX_PRODUCT];
	displayReportHeader();
	for (result = 0; result < MAX_PRODUCT; result++)
	{
		reportArray[result] = calculateReportData(catFoodDetail[result]);
		if (reportArray[result].per_weight < reportArray[result - 1].per_weight)
		{
			cheap_product = result;
		}
	}


	
	for (n = 0; n < MAX_PRODUCT; n++)
	{
		struct ReportData x = { 0 };

		x = reportArray[n];

		displayReportData(x, cheap_product);

		if (cheap_product == n)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(catFoodDetail[cheap_product]);

}