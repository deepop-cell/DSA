#include<iostream>
int max(int arr[], int n){
    int k=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>k){
            k=arr[i];
        }
    }
    return k;
}
int longest(std::string s, int k){
    int a[26]={0};
    int l=0;
    int r=0;
    int ans=0;
    std::string temp="";
    for(r=0;r<s.size();r++){
        temp+=s[r];
        a[s[r]-'A']++;
        int maxfreq=max(a,26);
        int windowsize=r-l+1;
        while(windowsize-maxfreq>k){
            a[s[l]-'A']--;
            l++;
            windowsize=r-l+1;
            maxfreq=max(a,26);
        }
        ans=(windowsize>ans)?windowsize:ans;
    }
    return ans;
}