#include<iostream>
#include<string.h>
bool check(std::string s1, std::string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    std::string d=s1+s1;
    if(d.find(s2)!=std::string::npos){
        return true;
    }
    else{
        return false;
    }
    
}