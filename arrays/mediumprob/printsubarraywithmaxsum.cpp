#include<iostream>
void printsubarraywithmaxsum(int arr[], int n){
    int sum=arr[0];
    int bestsum=arr[0];
    int start=0;
    int ansstart=0;
    int end=0;
    for(int i=1;i<n;i++){
        if(sum<0){
            sum=arr[i];
            start=i;
        }
        else{
            sum+=arr[i];
        }
        if(sum>bestsum){
            bestsum=sum;
            ansstart=start;
            end=i;
        }
    }
    for(int i=ansstart;i<=end;i++){
        std::cout<<arr[i]<<" ";
    }
}