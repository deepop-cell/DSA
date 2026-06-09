#include<iostream>
#include<climits>
int minsize(int arr[], int n, int k){
    int left=0;
    int sum=0;
    int minsize=INT_MAX;
    for(int right=0;right<n;right++){
        sum+=arr[right];
        while(sum>=k){
            minsize=((right-left+1)<minsize)?(right-left+1):minsize;
            sum-=arr[left];
            left++;
        }
    }
    return (minsize==INT_MAX)?0:minsize;
}