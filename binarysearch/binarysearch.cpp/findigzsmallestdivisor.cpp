#include<iostream>
int smallest_divisor(int n){
    int div=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            div=i;
            break;
        }
    }
    if(div==0){
        return n;
    }
    return div;
}