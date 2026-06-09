#include<iostream>
#include<bits/stdc++.h>
std::vector<int> lodaa(std::vector<int>v1,std::vector<int>v2){
    std::vector<int>uni;
    int i=0;
    int j=0;
    while(i<v1.size()&&j<v2.size()){
        if(uni.empty()||uni.back()!=v1[i]){
            uni.push_back(v1[i]);
            i++;
        }
        else if(uni.empty()||uni.back()!=v2[j]){
            uni.push_back(v2[j]);
            j++;
        }
        else{
            if(uni.empty()||uni.back()!=v1[i]){
            uni.push_back(v1[i]);
            i++;
            j++;
        }
    }
}
}
int main(){
int n1,n2;
std::cin>>n1;
std::cin>>n2;
std::vector<int>num1;
std::vector<int>num2;
for(int k=0;k<n1;k++){
    std::cin>>num1[k];
}
for(int a=0;a<n1;a++){
    std::cin>>num2[a];
}

std::vector<int>res=lodaa(num1,num2);
for(int alpha=0;alpha<res.size();alpha++){
    std::cout<<res[alpha]<<"\n";
}










    return 0 ;
}