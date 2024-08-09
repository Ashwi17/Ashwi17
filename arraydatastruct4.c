#include<stdio.h>
int main(){
    int n;
    float avg,average;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *ptr=arr;
    for(int i=0;i<n;i++){
        avg+=ptr[i];
    }
    average=avg/n;
    printf("%.2f",average);
    return 0;
}
