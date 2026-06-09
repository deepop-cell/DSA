#include<iostream>
void removestars(std::string x){
    std::string temp="";
    int i=0;
    while(i<x.length()){
        if(x[i]=='*'){
            temp.pop_back();
        }
        else{
            temp+=x[i];
        }
        i++;
    }
}