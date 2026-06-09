#include<iostream>
int maxidx(int arr[], int n){
    int index=0;
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    return index;
}
std::string sortbyfreq(std::string s){
    int arr[26]={0};
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
    }
    std::string temp="";
    while(1){
        int x=maxidx(arr,26);
        if(arr[x]==0){
            break;
        }

        for(int i=1;i<=arr[x];i++)
        temp+=(x+'a');
        arr[x]=0;
    }
    return temp;
}