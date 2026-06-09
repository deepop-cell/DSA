#include<iostream>
int power(int x,int r){
    if(r==0){
        return 1;
    }
    else{
        return x*power(x,r-1);
    }
}
int main(){
int n,m;
int ans=1;
std::cin>>n;
std::cin>>m;
for(int i=1;i<=n;i++){
    if(power(i,m)<=n){
        ans=i;
    }
    else{
        break;
    }
}
std::cout<<"The square root is :"<<ans;
    return 0;
}