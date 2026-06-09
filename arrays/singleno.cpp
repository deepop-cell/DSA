#include<iostream>
int single(int arr[],int n){
    for(int i=0;i<n;i++){
        bool fact=false;
        int set=arr[i];
        for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            else{
                if(arr[j]==set){
                    fact=true;
                    break;
                }

            }
        }
        if(fact==false){
            return set;
        }
    }
    return -1;
}