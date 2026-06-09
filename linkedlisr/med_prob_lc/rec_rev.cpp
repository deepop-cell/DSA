#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* reversal(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* newhead=reversal(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}