#include<iostream>
#include<climits>
int maxpoints(int arr[], int n, int k){
    int zheta=0;
    for(int i=0;i<n;i++){
        zheta+=arr[i];
    }
    if(k==n){
        return zheta;
    }
    int x=n-k;
    int left=0;
    int sum=0;
    int right=0;
    int minsum=INT_MAX;
        for( right=0;right<n-k;right++){
            sum+=arr[right];
        }
        while(right<n){
            if(sum<minsum){
                minsum=sum;
            }
            sum+=arr[right];
            sum-=arr[left];
            right++;
            left++;
        }
                    if(sum<minsum){
                minsum=sum;
            }
        return zheta-minsum;
}