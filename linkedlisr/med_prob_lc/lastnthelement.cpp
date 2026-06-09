#include<iostream>
struct node{
    int data;
    struct node* next;
};
struct node* nthelementfromlast(struct node*head,int n){
    struct node* p ;
    struct node* q;
    p=head;
    q=head;
    int i=0;
    while(i!=n){
        q=q->next;
        i++;
    }
        //head deletion case
    if(q==NULL){
        struct node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    struct node* del=p->next;
    p->next=del->next;
    free(del);
    return head;
}