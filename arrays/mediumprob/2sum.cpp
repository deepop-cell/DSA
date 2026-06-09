#include<iostream>

// void twosum( int arr[], int n, int k){(this is for sorted array only)
//     int low=0;
//     int high=n-1;
//     while(low<high){
//         int sum=arr[low]+arr[high];
//         if(sum==k){
//             std::cout<<"{"<<low<<","<<high<<"}";
//             break;
//         }
//         else if(sum<k){
//             low++;
//         }
//         else if(sum>k){
//             high--;

//         }
//     }
// }
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
