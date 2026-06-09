#include<iostream>
bool validanagram(std::string s1,std::string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<s1.length();i++){
        arr[s1[i]-'a']++;
        arr[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
}