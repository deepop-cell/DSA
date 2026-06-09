#include<iostream>
#include<cmath>
void rotate_array_by_k_places(int arr[],int n,int d){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n-d;i++){
        arr[i]=arr[n-d+i-1];
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        arr[i]=temp[j];
        j++;
    }
}
int main(){
int n;
std::cout<<"Enter the value of n:  \n";
std::cin>>n;
int d;
std::cout<<"Enter the value of d: \n";
std::cin>>d;
int arr[n];
for(int i=0;i<n;i++){
    std::cin>>arr[i];
}

rotate_array_by_k_places(arr,n,d);
for(int i=0;i<n;i++){
    std::cout<<arr[i];
}
    return 0;
}