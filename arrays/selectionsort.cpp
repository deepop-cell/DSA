#include<iostream>
int main(){
int n;
std::cin>>n;
int a[n];
for(int i=0;i<n;i++){
    std::cin>>a[i];
}
int min=a[0];
int k=0;
for(int i =0;i<n;i++){
    if(a[i]<min){
        min=a[i];
        k=i;
    }
    for(int j=i+1;j<n;j++){
        int temp=a[j];
        a[j]=a[k];
        a[k]=temp;
}
}




    return 0;
}