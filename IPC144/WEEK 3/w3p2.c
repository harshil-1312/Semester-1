
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




#include<stdio.h>
int main()
{
  char g1,t2,t3,s1,s2,s3; //type and size
  char bw1,bw2,bw3; // best serve with
  char x,y,z;
 int a,b1,b2,b3; //bag weight 
 float tp1,tp2,tp3; //temprature
 float g_to_l = 0.00220462;



    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &g1); 
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &s1); 
    printf("Bag weight (g): ");
    scanf(" %d", &b1); 
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bw1); 
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &tp1); 



    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &t2); 
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &s2); 
    printf("Bag weight (g): ");
    scanf(" %d", &b2); 
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bw2); 
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &tp2); 



    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &t3); 
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &s3);
    printf("Bag weight (g): ");
    scanf(" %d", &b3); 
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bw3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &tp3); 



    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    
    printf(" 1 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n", (g1 == 'l' || g1 == 'L'), (g1 == 'b' || g1 == 'B'), (s1 == 'c' || s1 == 'C'), (s1 == 'f' || s1 == 'F'), b1, ( b1 * (g_to_l)), (bw1 == 'y' || bw1 == 'Y'), tp1, (tp1 * 9/5) + 32 );

    printf(" 2 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n", (t2 == 'l' || t2 == 'L'), (t2 == 'b' || t2 == 'B'), (s2 == 'c' || s2 == 'C'), (s2 == 'f' || s2 == 'F'), b2, (b2 * (g_to_l)), (bw2 == 'y' || bw2 == 'Y'), tp2, (tp2 * 9/5) + 32 );
    
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n\n", (t3 == 'l' || t3 == 'L'), (t3 == 'b' || t3 == 'B'), (s3 == 'c' || s3 == 'C'), (s3 == 'f' || s3 == 'F'), b3, (b3 * (g_to_l)), (bw3 == 'y' || bw3 == 'Y'), tp3, (tp3 * 9/5) + 32);
    
    
    
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &x); 
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &z); 
    printf("Typical number of daily servings: ");
    scanf("%d", &a); 
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &y); 



    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (x == 'm' || x == 'M') && (g1 == 'l' || g1 == 'L'), (y == 'r' || y == 'R') && (s1 == 'c' || s1 == 'C'), (a < 5) || (b1 != 250), (z == 'y' || z == 'Y'), (y == 'r' || y == 'R') && (tp1 < 80));
    
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (x == 'r' || x == 'R') && (t2 == 'b' || t2 == 'B'), (y == 'c' || y == 'C') && (s2 == 'f' || s2 == 'F'), (a <= 9) && (b2 <= 500), (z == 'n' || z == 'N'), (y == 'c' || y == 'C') && (tp2 >= 50));
    
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", (x == 'm' || x == 'M') && (t3 == 'l' || t3 == 'L'), (y == 'c' || y == 'C') && (s3 == 'f' || s3 == 'F'), (a == 10) && (b3 <= 1000), (z == 'n' || z == 'N'), (y == 'c' || y == 'C') && (tp3 > 50));
    
    
    
    
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
  printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &x);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &z);
    printf("Typical number of daily servings: ");
    scanf("%d", &a); 
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &y);




    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
   
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (x == 'm' || x == 'M') && (g1 == 'l' || g1 == 'L'), (y == 'r' || y == 'R') && (s1 == 'c' || s1 == 'C'), (a < 5) && (b1 != 250), (z == 'y' || z == 'Y'), (y == 'r' || y == 'R') && (tp1 >= 50 ));
   
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (x == 'r' || x == 'R') && (t2 == 'b' || t2 == 'B'), (y == 'c' || y == 'C') && (s2 == 'f' || s2 == 'F'), (a <= 9) && (b2 < 500), (z == 'n' || z == 'N'), (y == 'c' || y == 'C') && (tp2 <= 50));
   
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", (x == 'm' || x == 'M') && (t3 == 'l' || t3 == 'L'), (y == 'c' || y == 'C') && (s3 == 'f' || s3 == 'F'), (a == 10) && (b3 <= 1000), (z == 'n' || z == 'N'), (y == 'c' || y == 'C') && (tp3 <= 50));
   
    printf("Hope you found a product that suits your likes!\n");
   
   
   
    return 0;

} 
