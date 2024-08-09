#include<stdio.h>
int main()
{
    char c;
    scanf("%c",&c);
    printf("Enter a character:%c",c);
    if((c>=65)&&(c<=90)||(c>=97)&&(c<=122))
    {
        printf("Alaphabet");
    }
    else
    {
        printf("Not alphabet");
    }
    return 0;
}
