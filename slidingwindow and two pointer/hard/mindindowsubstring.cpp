#include<iostream>
#include<climits>
std::string minwndw(std::string s, std::string t){
    int formed=0;
    int minLen=INT_MAX;
    int req=0;
    int start=-1;
    int need[26]={0};
    for(int i=0;i<t.length();i++){
        need[t[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(need[i]!=0){
            req++;
        }
    }
    int windows[26]={0};
    int left=0;
    for(int right=0;right<s.length();right++){
        windows[s[right]-'a']++;
        if(windows[s[right]-'a']==need[s[right]-'a']){
            formed++;
        }
        while(formed==req){
            if(right-left+1<minLen){
                minLen=right-left+1;
                start=left;

            }
            windows[s[left]-'a']--;
            if(windows[s[left]-'a']<need[s[left]-'a']){
                formed--;
            }
            left++;
        }
    }
    if(start==-1){
        return "";
    }
    return s.substr(start,minLen);
}