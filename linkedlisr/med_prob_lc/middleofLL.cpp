#include<iostream>
struct node{
    int data;
    struct node * next;
};
int length(struct node*head){
    if(head==NULL){
        return 0;
    }
    struct node*temp=head;
    int count=1;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
struct node* middlenode(struct node* head){
    int len = length(head);
    struct node* temp = head;
    int i=0;
    while(i!=len/2){
        temp=temp->next;
        i++;
    }

    return temp;
}