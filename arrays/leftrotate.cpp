#include<bits/stdc++.h>
int main(){
int n;
std::cout<<"Enter the value of n";
std::cin>>n;
std::vector<int>v(n);
for(int i = 0 ; i<n;i++){
    std::cin>>v[i];
}
int x=v[0];
for(int i = 1; i <n;i++){
    v[i-1]=v[i];
    
}
v[n-1]=x;





    return 0 ;
}