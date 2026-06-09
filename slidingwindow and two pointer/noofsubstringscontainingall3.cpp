#include<iostream>
int ans(std::string s){
    int left=0;
    int right=0;
    int a[3]={0};
    int x=0;
    for(int right=0;right<s.length();right++){
        a[s[right]-'a']++;
        while(a[0]>0 && a[1]>0 && a[2]>0){
            x+=s.length()-right;
            a[s[left]-'a']--;
            left++;
        }
    }
    return x;
}