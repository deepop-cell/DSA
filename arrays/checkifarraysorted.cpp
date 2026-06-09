#include<bits/stdc++.h>
int main(){
    int n;
    std::cout<<"Enter the value of n"<<"\n";
    std::cin>>n;
    if(n==0){
        std::cout<<"Enter a non zero value";
    }
std::vector<int>v(n);
bool sorted = true;
for(int i = 0 ; i<n;i++){
    std::cin>>v[i];
}
for(int i = 1;i<n;i++){
    if(v[i]<v[i-1]){
        sorted=false;
        break;
    }
    
}
if(sorted){
    std::cout<<"Array is sorted\n";
}
else{
    std::cout<<"Array is not sorted\n";
    
}






    return 0 ;
}