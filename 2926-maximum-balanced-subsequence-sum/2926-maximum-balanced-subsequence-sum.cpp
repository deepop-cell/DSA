class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        map<int,long long>mp;
        long long result=INT_MIN;
        for(int i=0;i<n;i++){
         
         auto it=mp.upper_bound(nums[i]-i); //jis bhi i par ho usse just bada wala nums[i]-i pe point krega ye 
         long long sum=nums[i];//jis i par khade ho.
         if(it!=mp.begin()){
            it--;//now <= wale pe point krega  
            sum+=it->second;
         }
         //ab iski entry krdo.
         mp[nums[i]-i]=max(sum,mp[nums[i]-i]);

         //ab wo delete krna hai jiska nums[i]-i se bada ho aur sum chota ho.
         it=mp.upper_bound(nums[i]-i);
         while(it!=mp.end() && it->second <=sum){
            mp.erase(it++);
         }

         result=max(result,sum);
        }
        return result;
        }
 
};