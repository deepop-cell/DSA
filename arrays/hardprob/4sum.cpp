#include<iostream>
#include<algorithm>
using namespace std;
void foursum(int arr[], int n,int k){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]){
                continue;
            }
            int alpha=k-(arr[i]+arr[j]);
            int left=j+1;
            int right=n-1;
            while(left<right){
                int sum=arr[left]+arr[right];
                if(sum<alpha){
                    left++;
                }
                else if(sum>alpha){
                    right--;
                }
                else if(sum==alpha){
                    cout << arr[i] << "," << arr[j] << "," 
     << arr[left] << "," << arr[right] << "\n";
                while(left<right && arr[left+1]==arr[left]){
                    left++;
                }
                while(left<right && arr[right-1]==arr[right]){
                    right--;
                }
                left++;
                right--;
                }
            }
        }
    }
}