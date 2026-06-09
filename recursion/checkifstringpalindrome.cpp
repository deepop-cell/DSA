#include<iostream>
#include<math.h>
bool palidnrome(const std::string& x,int start , int end){//const std string &x for using og string anf not copying everyfucking time
    if(start>=end){
        return true;
    }
    if(!isalnum(x[start])){
        return palidnrome(x,start+1,end);
    }
    if(!isalnum(x[end])){
        return palidnrome(x,start,end-1);
    }
    if(tolower(x[start])==tolower(x[end])){
        return palidnrome(x,start+1,end-1);
    }
    return false;
}