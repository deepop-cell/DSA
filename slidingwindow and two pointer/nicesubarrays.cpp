#include<iostream>
int nicesubarrays(int arr[], int n,int k){
    int count=0;
    int oddc=0;
    int l=0;
    int r=0;
    for(int r=0;r<n;r++){
        if(arr[r]%2!=0){
            oddc++;
        }
        while(oddc>k){
            if(arr[l]%2!=0){
                oddc--;
            }
            l++;
        }
        if(oddc==k){
            int x=l;
            while(x<=r && arr[x]%2==0){
                count++;
                x++;
            }
            count++;
        }

    }
    return count;
}