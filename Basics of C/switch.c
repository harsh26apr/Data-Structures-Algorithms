//A switch statement tests the value of a variable and compares it with multiple cases. 
//Once the case match is found, a block of statements associated with that particular case is executed.

#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number between 1 to 10:\n");
    scanf("%d",&num);


    switch (num) {
    case 1:
    printf("value is 1");
    break;
    
    case 2:
    printf("value is 2");
    break;
    
    case 3:
    printf("value is 3");
    break;
    
    case 4:
    printf("value is 4");
    break;

    case 5:
    printf("value is 5");
    break;

    case 6:
    printf("value is 6"); 
    break;
        
    case 7:
    printf("value is 7");
    break;

    case 8:
    printf("value is 8");
    break;

    case 9:
    printf("value is 9");
    break;
      
    case 10:
    printf("value is 10");
    break;
    
    default:
    printf("out of the range");
    break;
    }
    return 0;
}