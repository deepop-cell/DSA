class Solution {
public:
    void solve(int i,vector<int>&temp,vector<vector<int>>&res,vector<int>&coins){
        if(i==coins.size()){
            if(!temp.empty()){
                res.push_back(temp);
            }
            return;
        }
        //ab choice hai ya to current lo ya to mat lo.
        temp.push_back(coins[i]);
        solve(i+1,temp,res,coins);
        temp.pop_back();//backracking(undo)
        solve(i+1,temp,res,coins);
    }
    bool check(long long x,vector<int>&coins,vector<vector<int>>&res,int k){
        long long count=0;
        for(int i=0;i<res.size();i++){
            int sz=res[i].size();
            long long l=1;
            for(int j=0;j<sz;j++){
                l=lcm(l,res[i][j]);
            }
            if(sz%2!=0){
                count+=(x/l);
            }
            else{
                count-=(x/l);
            }
        }
        return count>=k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ///hum bs on answers kr skte hia, koi select  kr lete ai candidate jo hmmara kth pos pe hoga fir usse chote kitne numbers hai count krlo and check if wo k hai ya nhi . 
        long long low=INT_MAX;
        for(int &x:coins){
            low=min(low,(long long)x);
        }
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,temp,res,coins);//sare possible susbets banalo.
        long long  high=(long long )low*k;
        long long ans=-1;
        while(low<=high){
            long long mid=(low)+(high-low)/2;
            if(check(mid,coins,res,k)){
                ans=mid;
                high=mid-1;//aur chota dhundho
            }
            else{
                low=mid+1;//bade mai dhundho
            }
        }
        return ans;
    }
};