#include<iostream>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int length(struct node* head){
    int count=0;
    struct node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
struct node* intersection(struct node* head1, struct node* head2){
    int l1=length(head1);
    int l2=length(head2);
    struct node* temp1=head1;
    struct node* temp2=head2;
    int diff=abs(l1-l2);
    if(l1>l2){
        int i=0;
        while(i!=diff){
            temp1=temp1->next;
            i++;
        }
    }
    else if(l1<l2){
                int i=0;
        while(i!=diff){
            temp2=temp2->next;
            i++;
        }

    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}