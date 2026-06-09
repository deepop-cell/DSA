#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* deletehead(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* deleteend(struct node*head){
    if(head==NULL){
        return NULL;
    }
    struct node* curr=head->next;
    struct node* prev=head;
    while(curr->next!=NULL){
        curr=curr->next;
        prev=prev->next;
    }
    prev->next=NULL;
    free(curr);
    return head;
}
struct node* deleteatindex(struct node* head , int index){
    if(index==0){
        return deletehead(head);
    }
    struct node* curr=head->next;
    struct node* prev=head;
    int i=0;
    while(i!=index-1){
        curr=curr->next;
        prev=prev->next;
        i++;// for traversing
    }
    prev->next=curr->next;
    free(curr);
    return head;
}