#include<iostream>
struct node{
    int data;
    struct node* next;
};
void deletenode(struct node* head, struct node* del){
    struct node* temp=head;
    while(temp->next!=del){
        temp=temp->next;
    }
    temp->next=del->next;
    free(del);
    
}
struct node* remove_elements(struct node* head, int val){
    if(head==NULL){
        return head;
    }
    while(head!=NULL && head->data==val ){
        struct node* x=head;
        head=head->next;
        free(x);
    }
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            struct node* next=temp->next;
            deletenode(head,temp);
            temp=next;
        }
        else{
        temp=temp->next;
        }
    }
    return head;
}