class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //its asking whether there is an subarray with sum divisible by k ,
        int sum=0;
        int n=nums.size();
        map<int,int>mp;//sum , index
        mp[0]=-1;//jab sum , freq ho to mp[0]=1 aur jab sum,index ho to mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)!=mp.end()){
                //if same rem ws found previosuly then between that to curr, the sum is divisble by k.
                if(i-mp[rem]>=2){
                return true;
                }

            }
            else{
            mp[rem]=i;//if not foubd curr rem then only kro , aagr milgaya to wo door wale ko hee rehne do taki agar iske just next baad aae to uske lie len>2 ho.
            }

        }
        return false;
    }
};