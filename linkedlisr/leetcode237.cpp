#include<iostream>
struct node{
    int data;
    struct node* next;
};
void deleteatindex(struct node* x){
    x->data=x->next->data;
    x->next=x->next->next;
}