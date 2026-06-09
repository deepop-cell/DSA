#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
std::string reversestring( std::string x){
    int i=x.length()-1;
    std::string ans="";
    while(i>=0){
        while(i>=0 && x[i]==' '){
            i--;
        }
        if(i<0){
            break;
        }
        int j=i;
        while(j>=0 && x[j]!=' '){
            j--;
        }
        if(ans!=""){
            ans+=" ";
        }
        for(int k=j+1;k<=i;k++){
            ans+=x[k];

        }

        i=j-1;
    }
    return ans;

}