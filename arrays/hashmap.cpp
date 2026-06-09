#include<iostream>
#include<unordered_map>
int main(){
int n;
std::cout<<"Enter the value of n\n";
std::cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    std::cin>>arr[i];
}
//for(int x:arr)this makes copy of all elements in  array and traverses
std::unordered_map<int,int>freq;
for(int i=0;i<n;i++){
    freq[arr[i]]++;
}
for(std::pair<int,int>p:freq){
    std::cout<<p.first<<"  "<<p.second<<"\n";
}









    return 0;
}