#include<iostream>
int majority(int arr[], int n){
    int counter=0;
    int majority=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==majority){
            counter++;
        }
        else{
            if(counter==0){
                majority=arr[i];
                counter=1;
            }
            else{
                counter--;
            }
        }
    }
    return majority;
}