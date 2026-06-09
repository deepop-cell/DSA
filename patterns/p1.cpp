#include<iostream>
void pattern(int n){
    for(int i=0;i<n;i++){
        for(int i=0;i<n;i++){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
}