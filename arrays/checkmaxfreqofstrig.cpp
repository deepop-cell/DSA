#include<iostream>
#include<cstring>
int main(){
int n;
std::cout<<"Enter the value of n\n";
std::cin>>n;
char string[n];
for(int i=0;i<n;i++){
    std::cin>>string[i];
}
int arr[26];
memset(arr,0,sizeof(arr));
for(int i=0;i<n;i++){
    char ch=string[i];
    arr[ch-'a']++;
}
int index=0;
int max=arr[0];;
for(int j=0;j<26;j++){
    if(arr[j]>max){
        max=arr[j];
        index=j;
    }
}
std::cout<<"Maximum occurunce is of "<<'a'+index<<"  "<<max<<"times";

    return 0;
}