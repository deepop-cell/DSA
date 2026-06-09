#include<iostream>
using namespace std;
void majority(int arr[],int n){
    int cand1=0;
    int cand2=0;
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++){
    if(arr[i] == cand1){
    c1++;
}
else if(arr[i] == cand2){
    c2++;
}
else if(c1 == 0){
    cand1 = arr[i];
    c1 = 1;
}
else if(c2 == 0){
    cand2 = arr[i];
    c2 = 1;
}
else{
    c1--;
    c2--;
}
    }
    int f1,f2;
    f1=0;;
    f2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==cand1){
            f1++;
        }
        if(arr[i]==cand2){
            f2++;
        }
    }
    if(f1>(n/3)){
        cout<<cand1<<" ";
    }
    if(f2>(n/3) && cand1!=cand2){
        cout<<cand2<<" ";
    }
}