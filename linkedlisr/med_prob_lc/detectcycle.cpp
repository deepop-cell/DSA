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

