#include<stdio.h>
#include<stdlib.h>

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

int main(){
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
    return 0;
}