#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int findindex(int[],int,int,int,int);
int strCompare(char *s1,char *s2,int i){
    if(i>strlen(s1) && i>strlen(s2)){
        return 0;
    }

    if(i>strlen(s1)){
        return -1;
    }
    if(i>strlen(s2)){
        return 1;
    }

    if( (s1[i] | 32) < (s2[i] | 32) ){
        return -1;
    }
    else if(s1[i]>s2[i] || ((s1[i] | 32) > (s2[i] | 32))){
        return 1;
    }
    return strCompare(s1,s2,i+1);
}

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


struct Node{
    int data;
    struct Node* next;
};

int searchKey(struct Node* head,int k){
    if(head==NULL){
        return 0;
    }
    if(head->data==k){
        return 1;
    }
    return searchKey(head->next, k) ;
}

struct Node* InsertNode(struct Node* head,int x){
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
    new_Node->data=x;
    new_Node->next=NULL;
    if(head==NULL){
        head=new_Node;
        head->next=NULL;
        return head;
    }
        
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_Node;
        
        return head;
}

struct Node{
    int data;
    struct Node* next;
};

 struct Node* head;

void reverseList(struct Node* p){
 
    if(p->next == NULL){
 
        head = p;
        return;
    }
    reverseList(p->next);
 
    struct Node* rev = p->next;
    rev->next = p;
    p->next = NULL;
}

struct Node* InsertNode(struct Node* head,int x){
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
    new_Node->data=x;
    new_Node->next=NULL;
    if(head==NULL){
        head=new_Node;
        head->next=NULL;
        return head;
    }
        
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_Node;
        
        return head;
}

void PrintList(struct Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}


