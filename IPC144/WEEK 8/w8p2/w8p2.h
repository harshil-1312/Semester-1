
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





#define MAX_PRODUCT 3
#define per_serve 64
#define KG_IN_LBS 2.20462



struct ReportData
{
	int sku_num;
	
	int cal;
	
	int gm;
	
	double Sum_total;
	
	double per_weight;
	
	double per_cal;
	
	double cost;
	
	double mass;
	
	double kg;
};


struct CatFoodInfo
{
    int sku_num; 
    double value; 
    int cal; 
    double mass; 
};

int getIntPositive(int* num);

double getDoublePositive(double* num);

void openingMessage(const int num_products);

void getCatFoodInfo(const int i, struct CatFoodInfo* food);

void displayCatFoodHeader(void);

void displayCatFoodData(const int sku_num, const double* value, const int cal, const double* mass);

// part-2//

double convertLbsKg(const double* lbs_weight, double* kg);

int convertLbsG(const double* lbs_weight, int* gm);

void convertLbs(const double* lbs_to_kg, double* kg, int* gm);

double calculateServings(const int mass_volume, const int total_sum, double* result);

double calculateCostPerServing(const double* product_rate, const double* result, double* total_Cost);

double calculateCostPerCal(const double* cost_price, const double* calories, double* Cost_per_Calories);

struct ReportData calculateReportData(const struct CatFoodInfo detail_food_calorie);

void displayReportHeader(void);

void displayReportData(const struct ReportData reslut, const int least_value);

void displayFinalAnalysis(const struct CatFoodInfo cheap);

void start(void);

