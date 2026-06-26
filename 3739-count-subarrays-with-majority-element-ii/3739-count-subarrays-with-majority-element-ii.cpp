class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target) nums[i]=1;
            else nums[i]=-1;
        }
        
        long long validsubarray = 0; 
        int currsum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1; 
        long long smallerCount = 0; 

        for(int i=0; i<n; i++){
            if(nums[i] == 1) {
                // Agar sum badha, toh purana sum chhota ho gaya -> add karo
                smallerCount += mp[currsum];
                currsum++;
            } else {
                currsum--;
                smallerCount -= mp[currsum];
            }
            
            validsubarray += smallerCount;
            mp[currsum]++; 
        }
        
        return validsubarray;
    }
};