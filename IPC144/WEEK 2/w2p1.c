//***************************************************************************** 
// Full Name  : Harshil Prajapati
//student ID#: 175255215
//Email       : hprajapati8@myseneca.ca
//Secti/on    :IPC144ZRA.5605.2227
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation
//***************************************************************************** 


#include <stdio.h>
int main(void)
{
 int a;
 float x,y,z,subtotal,taxes;
 printf("Set Shirt Prices\n");
 printf("================\n");
 printf("Enter the price for a SMALL shirt: $");
 scanf("%f",&x);
printf("\nEnter the price for a MEDIUM shirt: $");
scanf("%f",&y);
printf("\nEnter the price for a LARGE shirt: $");
scanf("%f",&z);
printf("\nShirt Store Price list\n");
printf("======================");
printf("\nSMALL : $%0.2f",x);
printf("\nMEDIUM : $%0.2f",y);
printf("\nLARGE : $%0.2f\n",z);
printf("\nPatty's shirt size is 's'\n");
printf("Number of shirts patty is buying:");
scanf("%d",&a);
printf("\nPatty's shopping cart...\n");
printf("Contains  : %d shirts\n",a);
subtotal = y * a;
printf("Sub-total : %0.4f\n",subtotal);
printf("Taxes     : $18.6800\n");
taxes = subtotal + 18.6800;
printf("Total     : $%0.4f",taxes);

return 0;
}