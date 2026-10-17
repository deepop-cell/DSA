class Solution {
public:
    int getdigitsum(int n){
        int sum=0;
        while(n>0){
        sum+=(n%10);
        n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>og(nums.size());
        for(int i=0;i<n;i++){
        og[i]={getdigitsum(nums[i]),nums[i]};
        }
        sort(og.begin(),og.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[og[i].second]=i;
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            int curr=i;
            int right=mp[nums[i]];
            if(right!=curr){
                swap(nums[i],nums[right]);
                cnt++;
            }
        }
        return cnt;
    }
};