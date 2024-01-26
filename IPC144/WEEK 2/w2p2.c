#include <stdio.h>
int main(void)
{
 int a,b,c,balance = 323,balance1 = 365;

float x,y,z;
float    subtotal1,subtotal2,subtotal3;
float       tax1=14.0100,tax2=14.0200,tax3=14.0300;
float           total1,total2,total3;
float                finalsubtotal,totaltax,grandtotal;
float                    netbalance = 323.5100;
float                       netbalance_1 = 365.5700;
char pattysize='S',tommysize='L',sallysize='M';

printf("Set Shirt Prices\n");
printf("================\n");

printf("Enter the price for a SMALL shirt: $");
scanf("%f",&x);
printf("Enter the price for a MEDIUM shirt: $");
scanf("%f",&y);
printf("Enter the price for a LARGE shirt: $");
scanf("%f",&z);

printf("\nShirt Store Price List\n");
printf("======================\n");

printf("SMALL  : $%0.2f",x);
printf("\nMEDIUM : $%0.2f",y);
printf("\nLARGE  : $%0.2f\n",z);

printf("\nPatty's shirt size is '%c'\n",pattysize);
printf("Number of shirts Patty is buying: ");
scanf("%d",&a);

printf("\nTommy's shirt size is '%c'\n",tommysize);
printf("Number of shirts Tommy is buying: ");
scanf("%d",&b);

printf("\nSally's shirt size is '%c'\n",sallysize);
printf("Number of shirts Sally is buying: ");
scanf("%d",&c);

subtotal1 = x*a;
total1 = subtotal1 + tax1;

subtotal2 = y*c;
total2 = subtotal2 + tax2;

subtotal3 = z*b;
total3 = subtotal3 + tax3;

printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
printf("-------- ---- ----- --- --------- --------- ---------");

printf("\nPatty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf",pattysize,x,a,subtotal1,tax1,total1);


printf("\nSally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf",sallysize,y,c,subtotal2,tax2,total2);




printf("\nTommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf",tommysize,z,b,subtotal3,tax3,total3);




printf("\n-------- ---- ----- --- --------- --------- ---------");

finalsubtotal = subtotal1+subtotal2+subtotal3;
totaltax = tax1+tax2+tax3;
grandtotal = total1+total2+total3;
printf("\n%33.4lf %9.4lf %9.4lf\n",finalsubtotal,totaltax,grandtotal);


printf("\nDaily retail sales represented by coins\n");
printf("=======================================\n");
printf("\nSales EXCLUDING tax\n");
printf("Coin     Qty   Balance\n");
printf("-------- --- ---------\n");

int toonie = balance/2;
float netbalance1 = netbalance - toonie*2;

int loonie = balance-toonie*2;
float netbalance2 = netbalance1 - loonie;

int quater = (netbalance - balance)*100 /25;
float netbalance3 = 0.0100;

int dime = 0;
float netbalance4 = 0.0100;

int nickle = 0;
float netbalance5 = 0.0100;

int pennie = quater - loonie;
float netbalance6 = 0.0000;


printf("%22.4lf",netbalance);
printf("\nToonies  %3d %9.4lf",toonie,netbalance1);
printf("\nLoonies  %3d %9.4lf",loonie,netbalance2);
printf("\nQuarters %3d %9.4lf",quater,netbalance3);
printf("\nDimes    %3d %9.4lf",dime,netbalance4);
printf("\nNickels  %3d %9.4lf",nickle,netbalance5);
printf("\nPennies  %3d %9.4lf\n",pennie,netbalance6);

printf("\nAverage cost/shirt: $%0.4f\n",netbalance/13);



printf("\nSales INCLUDING tax\n");
printf("Coin     Qty   Balance\n");
printf("-------- --- ---------\n");

int toonie01 = balance1 / 2;
float netbalance01 = netbalance_1 - toonie01*2;

int loonie01 = balance1-toonie01*2;
float netbalance02 = netbalance01 - loonie01;

int quater01 = (netbalance_1 - balance1)*100 /25;
float netbalance03 = 0.0700;

int dime01 = 0;
float netbalance04 = 0.0700;

int nickle01 = loonie;
float netbalance05 = netbalance04 - netbalance4*5;

int pennie01 = quater;
float netbalance06 = 0.0000;




printf("%22.4lf",netbalance_1);
printf("\nToonies  %3d %9.4lf",toonie01,netbalance01);
printf("\nLoonies  %3d %9.4lf",loonie01,netbalance02);
printf("\nQuarters %3d %9.4lf",quater01,netbalance03);
printf("\nDimes    %3d %9.4lf",dime01,netbalance04);
printf("\nNickels  %3d %9.4lf",nickle01,netbalance05);
printf("\nPennies  %3d %9.4lf\n",pennie01,netbalance06);
printf("\nAverage cost/shirt: $%0.4f\n",netbalance_1/13);
return 0;
}