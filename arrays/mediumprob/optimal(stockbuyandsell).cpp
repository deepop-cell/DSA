#include<iostream>
int maxprofit(int arr[], int n){
    int i=1;
    int maxprofit=0;
    int minprice=arr[0];
    while(i<n){
        int currprice=arr[i];
        if(currprice<minprice){
            minprice=currprice;
        }
        if(currprice>minprice){
        int profit=currprice-minprice;
        if(profit>maxprofit){
            maxprofit=profit;
        }
        }
        i++;
    }
    return maxprofit;
 
}