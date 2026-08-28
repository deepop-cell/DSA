class Solution {
public:
int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int &x:nums){
            pq.push(x);
        }
        for(int i=0;i<k;i++){
            int curr=pq.top();
            pq.pop();
            curr++;
            pq.push(curr);
        }
        long long  l=1;
        while(!pq.empty()){
            l=1LL*(l*pq.top())%mod;
            pq.pop();
        }
        return l%mod;
    }
};