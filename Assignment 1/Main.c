#include<stdio.h>
#include<stdbool.h>
#include"Recursion.h"
int main()
{
    int n1;
    printf("Enter the size of first string\n");
    scanf("%d",&n1);
    char s1[n1];
    printf("Enter the string\n");
    scanf("%s",&s1);
    int n2;
    printf("Enter the size of second string\n");
    scanf("%d",&n2);
    char s2[n2];
    printf("Enter the string\n");
    scanf("%s",&s2);

    int ans=strCompare(s1,s2,0);
    printf("%d",ans);

  
    int n;
    printf("Enter the number of integers u wanna enter\n");
    scanf("%d",&n);
    int arr[n];
    int max_element;
    printf("Enter the integers\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    max_element=largestElement(arr,n);
    printf("%d",max_element);


    struct Node* head=NULL;
    int N;
    printf("Enter the elements u wanna enter\n");
    scanf("%d",&N);
    int x;
    printf("Enter the elements\n");
    while(N--){
        scanf("%d",&x);
        head=InsertNode(head,x);
    }
    int key,res;
    printf("enter the element u wanna search in list\n");
    scanf("%d",&key);
    res=searchKey(head,key);
    if(res==1){
        printf("True\n");
    }
    else{
        printf("False\n");
    }

      head=NULL;
    int N;
    printf("Enter the elements u wanna enter\n");
    scanf("%d",&N);
    int x;
    printf("Enter the elements\n");
    while(N--){
        scanf("%d",&x);
        head=InsertNode(head,x);
    }

    reverseList(head);
    PrintList(head);
    
  return 0;
} 