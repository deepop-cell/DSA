#include<iostream>
int binarysearch(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;

        }
        else{
            high=mid-1;
    }
    }
    return -1;
}
int lowerbound(int arr[],int n,int target){
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
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
int arr[n];
for(int i=0;i<n;i++){
    std::cin>>arr[i];
}
std::cout<<"Enter the target value\n";
int target;
std::cin>>target;
int index=binarysearch(arr,n,target);
if(index==-1){
    std::cout<<"Not found";
    std::cout<<"Insertion INdex is :"<<lowerbound(arr,n,target);

}
else{
    std::cout<<"found at "<<index;
}
  return 0;
}