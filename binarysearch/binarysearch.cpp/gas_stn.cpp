#include<iostream>
#include<stdlib.h>
using namespace std;
//classic example of floating binary search problem.

int max_gap(int arr[], int n){
    int mx = abs(arr[1] - arr[0]);
    for(int i = 0; i < n - 1; i++){
        if(abs(arr[i+1] - arr[i]) > mx){
            mx = abs(arr[i+1] - arr[i]);
        }
    }
    return mx;
}

bool canPlace(int arr[], int n, int k, double mid){
    int required = 0;

    for(int i = 0; i < n - 1; i++){
        double gap = abs(arr[i+1] - arr[i]);

        int stations = (int)(gap / mid);
        if(gap == stations * mid){
            stations--;
        }

        required += stations;
    }

    return required <= k;
}

double ans(int arr[], int n, int k){
    double low = 0;
    double high = max_gap(arr, n);

    while(high - low > 1e-6){
        double mid = (low + high) / 2;

        if(canPlace(arr, n, k, mid)){
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}