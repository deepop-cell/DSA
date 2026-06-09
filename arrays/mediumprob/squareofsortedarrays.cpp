#include<iostream>
#include<cmath>
void squaresortedarr(int arr[], int n){
    int i=0;
    int j=n-1;
    int temp[n];
    int k=n;
    while(i<=j){
        if(abs(arr[i])>abs(arr[j])){
            temp[k-1]=arr[i]*arr[i];
            i++;
        }
        else{
            temp[k-1]=arr[j]*arr[j];
            j--;
        }
        k--;
    }
}