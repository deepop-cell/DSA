#include<iostream>
int max(int x, int y){
    return (x>y)? x:y;
}
int maxconsecitveones(int arr[], int n,int k){
    int left=0;
    int right=0;
    int x=0;
    int ans=0;
    for(int right=0;right<n;right++){
        if(arr[right]==0){
            x++;
        }
        while(x>k){
            if(arr[left]==0){
                x--;
            }
            left++;
        }
        ans=max((right-left+1) , ans);

    }
    return ans;
}