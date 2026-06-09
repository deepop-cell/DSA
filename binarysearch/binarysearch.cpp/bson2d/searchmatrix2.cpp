#include<iostream>
bool check(int matrix[][100000],int r, int c,int target){
    int i=0;
    int j=c-1;
    while(i<r && j>=0){
            int search=matrix[i][j];
        if(search>target){
            j--;
        }
        else if(search<target){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
}