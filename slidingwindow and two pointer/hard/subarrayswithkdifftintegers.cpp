#include<iostream>
int numberofnonzero(int a[], int w){
    int y=0;
    for(int i=0;i<w;i++){
        if(a[i]!=0){
            y++;
        }
    }
    return y;
}
int subarrayswithkuniqueint(int arr[], int n, int k){
    int count=0;
    int a[10]={0};
    int right=0;
    int left=0;
    for(right=0;right<n;right++){
        a[arr[right]]++;
                while(numberofnonzero(a,10)>k){
            a[arr[left]]--;
            left++;
        }
        if(numberofnonzero(a,10)==k){
            int temp[10];
            for(int i=0;i<10;i++){
                temp[i]=a[i];
            }
            int x=left;
            while(temp[arr[x]]>1){
                temp[arr[x]]--;
                x++;
                count++;
            }
            count++;
        }
    }
    return count;
}