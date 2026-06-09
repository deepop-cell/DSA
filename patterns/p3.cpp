#include<iostream>
void pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}