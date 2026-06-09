#include<iostream>

int binsubarraywithsum(int arr[], int n, int k){
    int left = 0;
    int count = 0;
    int sum = 0;

    for(int right = 0; right < n; right++){
        sum += arr[right];

        while(sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            int x = left;

            while(x < right && arr[x] == 0){
                count++;
                x++;
            }

            if(x <= right || k != 0){
              count++;
            }  
        }
    }

    return count;
}