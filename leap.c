#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    printf("Enter a year:%d",num);
    if(num%4==0)
    {
        printf("is a leap year");
    }
    else
    {
        printf("is not a leap year");
    }
    return 0;
}
