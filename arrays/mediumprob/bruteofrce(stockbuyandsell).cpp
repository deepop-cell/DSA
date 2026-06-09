#include<iostream>
int maxprofit(int arr[], int n){
    int profit=0;
    int bestprofit=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            profit=arr[j]-arr[i];
            if(profit>bestprofit){
                bestprofit=profit;
                
            }
        }
    }
    return bestprofit;
}