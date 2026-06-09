#include<iostream>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* mergetwosortedlists(struct node* head1, struct node* head2){
    if(head1==NULL) return head2;
if(head2==NULL) return head1;
    struct node* i=head1;
    struct node* j=head2;
    struct node* newhead=(struct node*)malloc(sizeof(struct node));
    struct node* temp=newhead;
    while(i!=NULL && j!=NULL){
        if(i->data<j->data){
            temp->data=i->data;
            i=i->next;
            if(i!=NULL || j!=NULL){
         temp->next=(struct node*)malloc(sizeof(struct node));
          temp=temp->next;}
        }
        else if(i->data>j->data){
            temp->data=j->data;
            j=j->next;
            if(j!=NULL || i!=NULL){
            temp->next=(struct node*)malloc(sizeof(struct node));
             temp=temp->next;
            }
        }
        else{
            temp->data = i->data;
            i = i->next;
            if(i!=NULL || j!=NULL){
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp = temp->next;}
        }
    
}
    while(i!=NULL){
        temp->data=i->data;
        i=i->next;
        if(i!=NULL){
        temp->next=(struct node*)malloc(sizeof(struct node));
         temp=temp->next;
        }
    }
    while(j!=NULL){
        temp->data=j->data;
        j=j->next;
        if(j!=NULL){
        temp->next=(struct node*)malloc(sizeof(struct node));
         temp=temp->next;
        }
    }
                temp->next=NULL;
    return newhead;
}