#include<iostream>
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int removeval(int arr[],int n,int val){
    int left=0;
    int right=n-1;
    while(left<=right){
        if(arr[left]==val){
        swap(&arr[left],&arr[right]);
        right--;
        }
        else{
            left++;
        }
    }
    return left;
}