#include<iostream>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createnode(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct node* insertathead(struct node* head, int val){
    struct node* newnode=createnode(val);
        if(head==NULL){
        return newnode;
    }
    struct node* temp=head;
    newnode->next=temp;
    temp->prev=newnode;
    newnode->prev=NULL;
    head=newnode;
    return head;
}
struct node* insertatend(struct node* head, int val){
    struct node* newnode=createnode(val);
    if(head==NULL){
        return newnode;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;
}
struct node* insertatpos(struct node* head , int pos,int val){
    struct node* newnode=createnode(val);
    struct node* temp=head;
    if(head==NULL){
        return newnode;
    }
    if(pos==1){
        return insertathead(head,val);
    }
    for(int i=1;i<pos-1 && temp!=NULL ; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        return head;
    }
    if(temp->next==NULL){
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        return head;


    }
newnode->next = temp->next;
newnode->prev = temp;

temp->next->prev = newnode;
temp->next = newnode;
    return head;
}
struct node* deleteathead(struct node* head){
    if(head==NULL){
        return NULL;
        }
    struct node* temp=head;
    head=head->next;
    if(head==NULL){
        return NULL;
    }

    head->prev=NULL;
    free(temp);
    return head;
}
struct node* deleteatend(struct node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    struct node* temp=head;
    while( temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;}
struct node* deleteatpos(struct node* head , int pos){
        if(pos==1){
            return deleteathead(head);
        }
        struct node* temp=head;
        for(int i=1;i<pos && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){//outo of index
            return head;
        }
        if(temp->next==NULL){
            return deleteatend(head);
        }//last node
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
        return head;
    }