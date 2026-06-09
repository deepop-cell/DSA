#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* middlenode(struct node* head){
    struct node* slow=head;
    struct node* fast=head;
    struct node* temp;
    while(fast->next!=NULL && fast->next->next!=NULL){//because here we need first part of middle node
        slow=slow->next;
        fast=fast->next->next;
        
        
    }
    return slow;
}
struct node* reversal(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* newhead=reversal(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
bool palindrome(struct node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    struct node* middle=middlenode(head);
    struct node* secondhalf=reversal(middle->next);
    while(secondhalf!=NULL){
        if(head->data!=secondhalf->data){
            return false;
        }
        head=head->next;
        secondhalf=secondhalf->next;
    }
return true;
}
