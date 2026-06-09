#include<iostream>
int main(){
int n;
std::cout<<"Enter the value of n\n";
std::cin>>n;

int ans=1;
for(int i=1;i<=n;i++){
    if(i*i<=n){
        ans=i;
    }
    else{
        break;
    }
}
std::cout<<"The square root is :"<<ans;
}