
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

void  getCatFoodInfo(const int i, struct CatFoodInfo* food);

void displayCatFoodHeader(void);

void displayCatFoodData(const int sku_num, const double* value, const int cal, const double* mass);

void start(); 