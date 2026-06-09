#include<iostream>
void two_sum(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                std::cout<<"["<<i<<","<<j<<"]";
                return;
            }
        }
    }

}