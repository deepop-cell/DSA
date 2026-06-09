#include<iostream>
int atmost(int arr[],int n, int k){
    if(k<0){
        return 0;
    }
    int freq[20001] = {0};
    int left=0;
    int right=0;
    int distinct=0;
    int count=0;
    for(right=0;right<n;right++){
        freq[arr[right]]++;
        if(freq[arr[right]]==1){
            distinct++;
        }
        while(distinct>k){
            freq[arr[left]]--;
            if(freq[arr[left]]==0){
                distinct--;
            }
            left++;
        }
        count+=right-left+1;//no of subarrays ending at that right.
    }
    return count;
}
int subarrayswithkuniqueint(int arr[], int n, int k){
    return atmost(arr,n,k) - atmost(arr,n,k-1);
}