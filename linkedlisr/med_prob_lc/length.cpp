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
int cyclestart(struct node* head){
    if(cycle(head)){
    struct node* slow=head;
    struct node* fast=head;
    struct node* temp;
     struct node* temp2;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
         temp=slow;
         temp2=slow;

            break;
        }
    }
    while(head!=temp){
        head=head->next;
        temp=temp->next;
    }
    int len=1;
    while(temp!=temp2){
        temp=temp->next;
        len++;
    }
    return len;
    }
    else{
        return 0;
    }
}