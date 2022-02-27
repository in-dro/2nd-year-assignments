#include<stdio.h>

int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

int largestElement(int *arr,int n){
    if(n==1){
        return arr[0];
    }
    return max(largestElement(arr,n-1),arr[n-1]);
}

int main(){
    int n;
    printf("Enter the number of integers u wanna enter\n");
    scanf("%d",&n);
    int arr[n];
    int max_element;
    printf("Enter the integers\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    max_element=largestElement(arr,n);
    printf("%d",max_element);
    return 0;
}