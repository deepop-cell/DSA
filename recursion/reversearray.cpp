#include<iostream>
void swap(int x,int y){
    int temp=x;
    x=y;
    y=temp;
}
void reverse(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}