#include<iostream>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node* next;
};
struct node* twosum(struct node* head1, struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* newhead=(struct node*)malloc(sizeof(struct node));
    struct node* temp=newhead;
    int sum=0;
    int carry=0;
    while(ptr1!=NULL || ptr2!=NULL ||carry   ){//if ;ast node gives a carrry then create newnode and assign carry to it.
    int x=(ptr1==NULL)? 0 : ptr1->data;
    int y=(ptr2==NULL)? 0 : ptr2->data;
    int total=x+y+carry;
    if(total>=10){
        sum=total%10;
        carry=total/10;
    }
    else{
        sum=total;
        carry=0;
    }
        temp->data=sum;
        if(ptr1)ptr1=ptr1->next;
        if(ptr2)ptr2=ptr2->next;
        if(ptr1!=NULL || ptr2!=NULL || carry){
          temp->next = (struct node*)malloc(sizeof(struct node));//creation of next node.
          temp = temp->next;
          temp->next = NULL;
}      
    }
            return newhead;
}