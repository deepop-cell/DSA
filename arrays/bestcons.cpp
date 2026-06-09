#include<iostream>
#include<bits/stdc++.h>
int main(){
int n;
std::cout<<"Enter the value of n";
std::cin>>n;
std::vector<int>v(n);
for(int i =0;i<n;i++){
    std::cin>>v[i];
}
int count=1;
int best=1;
for(int j=0;j<n-1;j++){
    if(v[j]==v[j+1]){
        count++;
    }
    else{
        if(count>best){
            best=count;
        }
         count=1;
    }
}
std::cout<<"Output: "<<best;
    return 0;
}