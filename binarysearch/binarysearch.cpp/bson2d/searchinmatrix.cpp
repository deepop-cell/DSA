#include<iostream>
bool search(int arr[][100000], int r, int c,int target){
    int low=0;
    int high=r*c-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int x=mid/c;
        int y=mid%c;
        if(arr[x][y]==target){
            return true;
        }
        else if(arr[x][y]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}