class Solution {
public:
int atmost(vector<int>&nums,int k){
        int l=0;
        int r=0;
        unordered_map<int,int>mp;
        int cnt=0;
        for(r=0;r<nums.size();r++){
        mp[nums[r]]++;
        while(mp.size()>k){
            //while invalid shrink left.
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
        }
        //now we have a valid window, if it has atmost k differnt integers . 
        //thne all of its smaller will also havr . 
        cnt+=r-l+1;
        }
        return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //always remeber this. in slding window if exaclty k asked , then do atmostk -atmost(k-1)/.
    return atmost(nums,k)-atmost(nums,k-1);
    }
};