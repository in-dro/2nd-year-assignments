#include<stdio.h>
#include<stdlib.h>

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

int main(){
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