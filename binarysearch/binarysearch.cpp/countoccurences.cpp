#include<iostream>
int lowerBound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }

    }
    return ans;
}
int higherbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    
    }
    return ans;
}
int main(){
int n;
std::cout<<"Enter the value of n\n";
std::cin>>n;
int target;
std::cout<<"Enter target value:\n";
std::cin>>target;
int arr[n];
for(int i=0;i<n;i++){
    std::cin>>arr[i];
}
int count=higherbound(arr,n,target)-lowerBound(arr,n,target);
std::cout<<"Occurence of target digit is : "<<count<<"times";
return 0;


}