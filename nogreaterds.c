#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (a>b && a>c){
        printf("A is greater=%d",a);
    }
    else if(b>a&&b>c){
        printf("B is greater=%d",b);
    }
    else{
        printf("C is greater=%d",c);
    }
}
