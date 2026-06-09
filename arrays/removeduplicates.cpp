#include<bits/stdc++.h>
int main(){
int n;
std::cout<<"Enter the value of n";
std::cin>>n;
std::vector<int>arr(n);
for(int i = 0 ; i<n;i++){
std::cin>>arr[i];
}
std::set<int>st;
for(int i = 0 ; i <n;i++){
    st.insert(arr[i]);
}
for(int x : st){
    std::cout<<x<<" ";
}
std::cout<<st.size();







    return 0;
}