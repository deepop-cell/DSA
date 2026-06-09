#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
void reverserange(std::string &s,int start,int end){
   
    while(start<end){
        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }

}
std::string reversewords(std::string s){
    int n=s.length();
    reverserange(s,0,n-1);
    int i=0;
    while(i<n){
        while(i<n && s[i]==' '){
            i++;
        }
        int  start=i;
        while(i<n && s[i]!=' '){
            i++;
        }
        int end=i-1;
        if(start<=n){
        reverserange(s,start,end);
        }
    }
    return s;
}

int main(){
std::string str;










    return 0;
}