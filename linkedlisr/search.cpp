#include<iostream>
struct node{
    int data;
    struct node* next;
};
bool search(struct node* head,int key){
    bool check=false;
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            check=true;
        }
        temp=temp->next;

    }
    return check;
}