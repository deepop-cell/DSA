#include<iostream>
struct node{
    int data;
    struct node* next;

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
struct node* deletemiddle(struct node* head){
    struct node* del=middlenode(head);
    if(del==head){
        return NULL;
    }
    struct node* temp=head;
    while(temp->next!=del){
        temp=temp->next;
    }
    temp->next=del->next;
    free(del);
    return head;
}