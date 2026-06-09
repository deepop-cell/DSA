#include<iostream>
struct node{
    int data;
    struct node* next;
};
bool cycle(struct node* head){
    struct node* slow=head;
    struct node* fast=head;
   while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        return true;
    }
 
   }

   return false;
}
struct node* cyclestart(struct node* head){
    if(cycle(head)){
    struct node* slow=head;
    struct node* fast=head;
    struct node* temp;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
         temp=slow;
            break;
        }
    }
    int i=0;
    while(head!=temp){
        head=head->next;
        temp=temp->next;
    }
    return temp;}
    else{
        return NULL;
    }
}