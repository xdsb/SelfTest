#include<stdio.h>
int main(){
   for(int j=0;j<10;j++)
   {
    for(int i=0;i<j+1;i++)
    {
       printf("*");
       if(i==j)
       {
         printf("\n");
       }
    }
   }
    printf("Hello,This my first Git!\n");

    return 0;
}