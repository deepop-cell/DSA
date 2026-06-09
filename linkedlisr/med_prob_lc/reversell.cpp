#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* reverselist(struct node* head){
    struct node* prev=NULL;
    struct node* curr=head;
    struct node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}