#include<iostream>
int sumoffirstn(int n){
    if(n==1){
        return 1;
    }
    return n+sumoffirstn(n-1);
}