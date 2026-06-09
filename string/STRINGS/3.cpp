#include<iostream>
#include<cstring>
#include<stdlib.h>
int main(){
std::string number;
getline(std::cin,number);
int start=0;
int end=number.length()-1;
while(start < number.length() && number[start] == '0'){
    start++;
}
if((number[end]-'0')%2==0){
for(int j=end;j>=start;j--){
    
    if(((number[j])-'0')%2!=0){
        end=j;
        break;
    }
}
}
std::string temp="";
for(int i=start;i<=end;i++){
    temp+=number[i];

}
if(end>=start){
std::cout<<temp;
}
else if(end<start){
    std::cout<<"NULL";
}
    return 0;
}