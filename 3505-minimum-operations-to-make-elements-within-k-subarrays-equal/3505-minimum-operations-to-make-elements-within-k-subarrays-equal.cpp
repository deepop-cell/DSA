class Solution {
public:
long long dp[100001][16];
long long cost[100001];
    long long s(vector<int>&nums,int l , int h){
        vector<int>t(nums.begin()+l,nums.begin()+h+1);
       nth_element(t.begin(), t.begin() + t.size() / 2, t.end());
        int mn=t[t.size()/2];
        long long cst=0;
        for(auto &x:t){
            cst+=(abs(x-mn));
        }
        cost[l]=cst;//storing it 
        return cst;
    }
    long long solve(int i,vector<int>&nums,int x, int k){
        if(k==0){
            return 0;
        }
        if(i>=nums.size()){
            //ye invalid hai jab sare hee skip krdiye ho 
            return 1e15;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        //we have options ya to current wlal interval elelo ya to skip krdo 
         long long take=1e15;
        if(i+x<=nums.size()){
            if(cost[i]!=-1){
        take=cost[i] + solve(i+x,nums,x,k-1);
            }
            else{
                take=s(nums,i,i+x-1) + solve(i+x,nums,x,k-1);
            }
        }
        long long skip=solve(i+1,nums,x,k);
        return  dp[i][k]=min(take,skip);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        if(x==n && k==1){
            return s(nums,0,n-1);
        }
        multiset<int> left,right;
long long sum_left=0,sum_right=0;
auto balance=[&](){
    while(left.size()>right.size()+1){
        auto it=prev(left.end());
        right.insert(*it);
        sum_right+=*it;
        sum_left-=*it;
        left.erase(it);
    }
    while(right.size()>left.size()){
        auto it=right.begin();
        left.insert(*it);
        sum_left+=*it;
        sum_right-=*it;
        right.erase(it);
    }
};
for(int i=0;i<n;i++){
    if(left.empty()||nums[i]<=*left.rbegin()){
        left.insert(nums[i]);
        sum_left+=nums[i];
    }else{
        right.insert(nums[i]);
        sum_right+=nums[i];
    }
    balance();
    if(i>=x){
        int out_val=nums[i-x];
        auto it=right.find(out_val);
        if(it!=right.end()){
            sum_right-=out_val;
            right.erase(it);
        }else{
            it=left.find(out_val);
            sum_left-=out_val;
            left.erase(it);
        }
        balance();
    }

    if(i>=x-1){
        long long median=*left.rbegin();
        cost[i-x+1]=sum_right-sum_left+median*((long long)left.size()-(long long)right.size());
    }
    }
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,x,k);
    }
};