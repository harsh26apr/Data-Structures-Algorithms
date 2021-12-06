// C program to show all datatypes

# include <stdio.h>

int main()
{
 int   sum;
 float money;
 char  letter;
 double pi;

 sum = 10;   // assign integer value
 money = 2.21; // assign float value
 letter = 'A'; // assign character value 
 pi = 2.01E6;  // assign a double value 

 printf("value of sum = %d \n", sum );
 printf("value of money = %f \n", money );
 printf("value of letter = %c \n", letter );
 printf("value of pi = %en", pi );
 getchar();
 return (0);
}