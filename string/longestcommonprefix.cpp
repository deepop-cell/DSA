#include<iostream>
std::string longestcommon(std::string arr[], int n){
    std::string ans="";
    for(int i=0;i<arr[0].size();i++){
        char ch=arr[0][i];
        for(int j=1;j<n;j++){
            if(i>=arr[j].size() || arr[j][i]!=ch){
                return ans;
            }
        }
        ans+=ch;
    }
    return ans;
}