#include<bits/stdc++.h>
int main(){
    int n;
    std::cout<<"Enter the value of n"<<"\n";
    if(n==0){
        std::cout<<"Enter a non zero value";
    }

    std::cin>>n;
std::vector<int>v(n);
for(int i = 0 ; i < n;i++){
    std::cin>>v[i];
}
int max = v[0];
for(int i = 1 ; i < n;i++){
    if(v[i]>max){
        max=v[i];
    }
}
std::cout<<"The maximum element of array is :"<<" "<< max;








    return 0 ;
}