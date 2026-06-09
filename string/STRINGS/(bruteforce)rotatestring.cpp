#include<iostream>
#include<stdlib.h>
void rotate_string(std::string& s1,int d){
 std::string temp="";
 for(int i=0;i<=s1.length()-1;i++){
    temp+=s1[(i+d)%s1.length()];
 }
 s1=temp;


}
bool check_string(std::string s1,std::string s2,int n){
if(s1.length()!=s2.length()){
    return false;
}    
    for(int i=0;i<n;i++){
        std::string temp=s1;
        rotate_string(temp,i);
        if(temp==s2){
            return true;
        }
        
    
    }
    return false;
    
}