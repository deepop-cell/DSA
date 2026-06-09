#include<iostream> 
#include<climits>
double median_sortedarrays(int A[], int B[], int n, int m){
    if(n>m){
        return median_sortedarrays(B,A,m,n);
    }
    int low=0;
    int high=n;
    int leftsize=(n+m+1)/2;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cut1=mid;
        int cut2=leftsize-cut1;
        int leftA,leftB,rightA,rightB;
        if(cut1==0){
            leftA=INT_MIN;
        }
        else{
            leftA=A[cut1-1];
        }
        if(cut1==n){
            rightA=INT_MAX;
        }
        else{
            rightA=A[cut1];
        }
        if(cut2==0){
            leftB=INT_MIN;
        }
        else{
            leftB=B[cut2-1];
        }
        if(cut2==m){
            rightB=INT_MAX;
        }
        else{
            rightB=B[cut2];
        }
        if(leftA<=rightB  && leftB<=rightA){
            if((n+m)%2==0){
                int leftmx=(leftA>leftB?leftA:leftB);
                int rightmn=(rightA<rightB? rightA:rightB);
                return (leftmx+rightmn)/2.0;
            }
            else{
                return (leftA>leftB?leftA:leftB);
            }
        }
        else if(leftB>rightA){
            low=cut1+1;

        }
        else if(leftA>rightB){
            high=cut1-1;
        }
}
    }