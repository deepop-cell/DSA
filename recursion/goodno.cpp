#include<iostream>
#include<iostream>
int pow( int x , int n){
    int mod=1000000007;
    if(n==0){
        return 1;
    }
    int half=pow(x,n/2);
    if(n%2==0){
        return (half*half)%mod;
    }
    else{
        return (x*half*half)%mod;
    }

}
int countevenpos(int n){
    return (n+1)/2.0;
}
int countoddpos(int n){
    return n-(n+1)/2.0;
}
int goodnos(int n){
    int x=countevenpos(n);
    int y=countoddpos(n);
    int ans=pow(5,x)*pow(4,y);
    return ans%(pow(10,9)+7);
}