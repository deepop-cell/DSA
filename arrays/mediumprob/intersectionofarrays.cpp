#include<iostream>
#include<bits/stdc++.h>
int subarraysumk(int arr[], int n , int k){
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int need=sum-k;
        if(mp.find(need)!=mp.end()){
            count+=mp[need];
        }
            mp[sum]++;

    }
    return count;
}