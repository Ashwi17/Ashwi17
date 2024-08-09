#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *ptr=arr;
    for(int i=0;i<n;i++){
        printf("elements=%d",ptr[i]);
    }
    return 0;
}
