#include<iostream>
struct node{
    int data;
    struct node* next;
};
void traversal(struct node* ptr){
    while(ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    struct node* fnode=(struct node*)malloc(sizeof(struct node));
    head->next=fnode;
    fnode->data=12;
    struct node* snode=(struct node*)malloc(sizeof(struct node));
    fnode->next=snode;
    snode->next=NULL;
    snode->data=19;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    traversal(head);
return 0;
}