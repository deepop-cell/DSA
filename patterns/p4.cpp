#include<iostream>
void pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            std::cout<<n-j+1;
        }
        std::cout<<"\n";
    }
}