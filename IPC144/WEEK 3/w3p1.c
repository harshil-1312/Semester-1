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


#include <stdio.h>
int main()
{

const int id1 = 111, id2 = 222, id3 = 111;

char tax1 = 'Y', tax2 = 'N', tax3 = 'N';

const float cost1 = 111.49, cost2 = 222.99, cost3 = 334.49;

const float average = (cost1 + cost2 + cost3) / 3;

const float testvalue = 330.99;

printf("Product Information\n");
printf("===================\n");



printf("Product-1 (ID:%d)\n",id1);
printf(" Taxed: %c\n",tax1);
printf(" Price: $%0.4f\n\n",cost1);



printf("Product-2 (ID:%d)\n",id2);
printf(" Taxed: %c\n",tax2);
printf(" Price: $%0.4f\n\n",cost2);



printf("Product-3 (ID:%d)\n",id3);
printf(" Taxed: %c\n",tax3);
printf(" Price: $%0.4f\n\n",cost3);


printf("The average of all prices is: $%0.4f\n\n",average);


printf("About Relational and Logical Exoressions!\n");
printf("========================================\n");
printf("1. These expressions evaluate to TRUE or FALSE\n");
printf("2. FALSE: is always represented by integer value 0\n");
printf("3. TRUE: is represented by any interger value other than 0\n\n");



printf("Some Data Analysis...\n");
printf("=====================\n");

const int
a = cost1 < cost2;

printf("1. Is product 1 taxable? -> %d\n\n",a);

const int
b = cost2 != cost3;

printf("2. Are products 2 and 3 both not taxable (N)? -> %d\n\n",b);

const int
c = id3 == id2;

printf("3. Is product 3 less than test value ($%0.2f)? -> %d\n\n",testvalue,c);

const int
d = cost3 > cost1 + cost2;

printf("4. Is the price of product 3 more than product 1 and 2 combined? -> %d\n\n",d);

const int
e = cost1 >= (cost3 - cost2);

printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? -> %d",e);
printf(" (price difference: $%0.2f)\n\n",cost3-cost2);

const int
f = cost2 >= average;

printf("6. Is price of product 2 equal to or more than the average price? ->%d\n\n",f);

const int
g = id1 != id3;

printf("7. Based on product ID, product 1 is unique -> %d\n\n",g);

const int
h = id1 == id3;

printf("8. Based on product ID, product 2 is unique -> %d\n\n",h);


const int
i = id3 != id1;

printf("9. Based on product ID, product 3 is unique -> %d\n\n",i);






return 0;
}
