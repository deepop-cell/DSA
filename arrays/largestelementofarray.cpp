#include<iostream>
int main(){
    int n;
    std::cin>>n;
    int array[n];
    for(int a = 0 ; a<n;a++){
        std::cin>>array[a];
    }
    int i,j;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(array[j]>array[j+1]){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            
        }
    }
}
    
    std::cout<<"The largest element of array is :"<<array[n-1];





    return 0 ;
}
//this code is right but sorting is O(n2).. we can do it in O(n);