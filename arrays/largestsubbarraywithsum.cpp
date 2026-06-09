#include<iostream>
int max(int x,int y){
    return (x>y)?x:y;
}
int main(){
int n;
std::cin>>n;
int t;
std::cin>>t;
int arr[n];
for(int i=0;i<n;i++){
    std::cin>>arr[i];
}
int best=0;
for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
        sum+=arr[j];
        
        if(sum==t){
            best=max(best,j-i+1);
        }
    }
}


std::cout<<"The subarray with the given target sum has length:"<<best;
return 0;
}