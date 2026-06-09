#include<iostream>
int main(){
int n;
std::cout<<"Enter the size of array\n";
std::cin>>n;
int a[n];
int k;
std::cout<<"Enter what number u want to find index";
std::cin>>k;
for(int i = 0 ; i<n;i++){
    std::cin>>a[i];
}
for(int j=0;j<n;j++){
    if(a[j]==k){
        std::cout<<"Element found at "<<j<<"  index";
        break;
    }
}
    return 0 ;
}