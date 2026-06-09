#include<iostream>
void printNto1(int n){
    if(n==0){
        return;
    }
    std::cout<<n<<" ";
    printNto1(n-1);
}