#include<iostream>
struct node{
    int data;
    struct node* next;
};
int length(struct node* head){
    if(head==NULL){
        return 0;
    }
    int count=1;
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
struct node* roatate(struct node* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    int len=length(head);
    k=k%len;
    if(k==0){//ie k=len
        return head;
    }
    struct node* temp=head;
    int x=(len-k);

    for(int i=1;i<x && temp!=NULL;i++){
        temp=temp->next;
    }
    struct node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
