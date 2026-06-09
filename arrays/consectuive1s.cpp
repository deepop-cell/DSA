#include<iostream>
int max1s(int arr[], int n){
    int count=0;
    int best=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
        }
        else{
            if(count>best){
                best=count;
            }
             count=0;
        }
    }
    best=best>count? best:count;
    return best;
}