#include<iostream>
#include<algorithm>
using namespace std;

void threesum(int arr[], int n){
    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        //for skippping duplciate fixed
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }

        int k = -arr[i];
        int left = i+1;
        int right = n-1;

        while(left < right){
            int sum = arr[left] + arr[right];

            if(sum > k){
                right--;
            }
            else if(sum < k){
                left++;
            }
            else{
                cout << arr[i] << "," << arr[left] << "," << arr[right] << "\n";
//for skipping duplicates
                while(left < right && arr[left] == arr[left+1]){
                    left++;
                }

                while(left < right && arr[right] == arr[right-1]){
                    right--;
                }

                left++;
                right--;
            }
        }
    }
}