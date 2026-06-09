#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* oddevenlink(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* odd=head;
    struct node*even=head->next;
    struct node*evenhead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}

