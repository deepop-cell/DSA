#include<iostream>
#include <unordered_map>
int largestsumsubaaraywithsum0(int arr[], int n){
    unordered_map<int,int>mp;
    int prefixsum=0;
    int len=0;
    int bestlen=0;
    for(int i=0;i<n;i++){
        prefixsum+=arr[i];
        if(prefixsum==0){
            bestlen=i+1;
        }
        if(mp.find(prefixsum)!=mp.end()){
            len=i-mp[prefixsum];
            if(len>bestlen){
                bestlen=len;
                len=0;
            }

        }
        else{
        mp[prefixsum]=i;
        }

    }
    return bestlen;
}