#include<iostream>
struct node{
    int data;
    struct node * next;
};
struct node* middlenode(struct node* head){
    struct node* slow=head;
    struct node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}