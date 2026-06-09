#include<iostream>
#include<climits>
int max(int x, int y){
    return (x>y)? x:y;
}
int min(int x , int y){
    return (x<y)? x:y;
}
int kth_element(int a[], int b[], int n, int m,int k){
    if(n>m){
        return kth_element(b,a,m,n,k);
    }
    int low=0;
    int high=n;
    int leftsize=k;
    while(low<=high){
        int mid=(low+high)/2;
        int cut1=mid;
        int cut2=leftsize-cut1;
        int la,lb,ra,rb;
        if(cut1==0){
            la=INT_MIN;
        }
        else{
            la=a[cut1-1];
        }
        if(cut1==n){
            ra=INT_MAX;
        }
        else{
            ra=a[cut1];
        }
        if(cut2==0 || cut2<0){
            lb=INT_MIN;
        }
        else{
            lb=b[cut2-1];
        }
        if(cut2==m || cut2>m){
            rb=INT_MAX;
        }
        else{
            rb=b[cut2];
        }
        if(la<=rb && lb <= ra){
            return max(la,lb);
        }
        else if(la>rb){
            high=mid-1;
        }
        else if(lb>ra){
            low=mid+1;
        }

        
    }
}