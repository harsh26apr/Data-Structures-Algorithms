#include <stdio.h>
int main()
{
  char str[1000], rev[1000];
  int i, j, count = 0;
  printf("\nEnter a string: %s", str);
  scanf("%s", str);
  
  //finding the length of the string

  while (str[count] != '\0')
  {
    count++;
  }
  j = count - 1;

  //reversing the string by swapping
  for (i = 0; i < count; i++)
  {
    rev[i] = str[j];
    j--;
  }
 
  printf("\nReversed String: %s \n", rev);
}