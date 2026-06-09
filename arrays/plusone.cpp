#include<iostream>
bool canplace(int arr[], int  n,int k){
   if(n==1 && arr[0]==0){
      return k<=1;
   }
   for(int i=0;i<n;i++){
      int leftbed,rightbed;
      if(i==0){
         leftbed=0;
         rightbed=arr[i+1];
      }
      else if(i==n-1){
         rightbed=0;
         leftbed=arr[i-1];
      }
      else{
      leftbed=arr[i-1];
      rightbed=arr[i+1];
      }
      if(arr[i]==0 && leftbed==0 && rightbed==0){
         k--;
         arr[i]=1;//placing flowers.
      }
   }
   
   return k<=0;
}