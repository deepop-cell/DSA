#include<iostream>
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void sortarray(int arr[], int n){
    int left=0;
    int right=n-1;
    int mid=0;
    while(mid<=right){
        if(arr[mid]==0){
            swap(arr[mid],arr[left]);
            mid++;
            left++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[right]);
            right--;
        }
    }
}