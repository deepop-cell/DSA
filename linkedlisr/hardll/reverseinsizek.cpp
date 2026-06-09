#include<iostream>
struct node{
    int data;
    struct node* next;
};
int lentgth(struct node* head){
    struct node* temp=head;
    int i=0;
    while(temp!=NULL){
        temp=temp->next;
        i++;
    }
    return i;
}
struct node* reverseinsizek(struct node* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* curr=head;
    struct node* prevtail=NULL;
    while(curr!=NULL){
    struct node* check=curr;
    int count=0;
    while(check!=NULL && count<k){
        check=check->next;
        count++;
    }
    if(count<k){
        break;//no group, no need to reverse.
    }
    struct node* groupstart=curr;
    struct node* prev=check;//prev=next groupstart
    for(int i=0;i<k;i++){
        struct node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    if(prevtail==NULL){
        head=prev;
    }
    else{
    prevtail->next=prev;
    }
    prevtail=groupstart;

}
return head;
}