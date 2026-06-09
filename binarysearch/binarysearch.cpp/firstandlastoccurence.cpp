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
int BinarySearch(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
    }
    return -1;
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
if(BinarySearch(arr,n,target)==-1){
    std::cout<<"[-1,-1]";
}
else{
    std::cout<<"["<<lowerBound(arr,n,target)<<","<<higherbound(arr,n,target)-1<<"]";
}
return 0;
}