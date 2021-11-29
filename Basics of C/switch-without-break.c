#include <stdio.h>
void main() 
{
  int r_num = 9049;
  // printf(" %d " ,r_num%4);
  switch(r_num%4)
  {
  case 1: printf("1 ");
  case 2: printf("2 ");
  case 3: printf("3 ");
  case 0: printf("4 ");
  }
}