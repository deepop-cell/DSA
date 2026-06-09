#include<iostream>
struct node{
    int data;
    struct node*next;
};
void traversal(struct node* ptr){
    while(ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
struct node* createnewnode(int val){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
struct node* insertion_head(struct node* head,int val){
    struct node* newnode=createnewnode(val);
    //case1 insert at head
    
        newnode->next=head;
        head=newnode;
        return head;
    
    

    
}
struct node* insertion_end(struct node*head,int val){
    struct node* newnode=createnewnode(val);
    struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;//travserse till end.
        }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
struct node* insertion_index(struct node*head , int index, int val){
    if(index==0){
        return insertion_head(head,val);
    }
    struct node* newnode=createnewnode(val);
    struct node* temp=head;
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
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
    int val;
    std::cout<<"Enter value to be added\n";
    std::cin>>val;
    int index;
    std::cout<<"Enter index";
    std::cin>>index;
    head=insertion_index(head,index,val);

    traversal(head);
return 0;
}