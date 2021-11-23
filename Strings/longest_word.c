//Finds the length of the longest word in a text with no punctuation or 
//special characters of any kind - only contains words. 

#include<stdio.h>
int main(void){
    int i,length;
    int max=0;
    int num=0;
    char word[101];
    
    scanf("%d",&num);
    for(i=0;i<num;i++){
       scanf("%s",word);
       length =0;
       while(word[length]!='\0'){
           length++;
       }
       
       if(length>max){
           max=length;
       }
        
    }
    printf("%d \n",max);
    return 0;
    
}