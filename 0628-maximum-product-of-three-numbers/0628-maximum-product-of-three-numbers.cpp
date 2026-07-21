class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int>pq1;//maxheap
        priority_queue<int,vector<int>,greater<int>>pq2;//minheap.
        for(auto &x:nums){
            pq1.push(x);
            pq2.push(x);
        }
        int l1=1;//for neg
        int l2=1;//for pos.
        l1*=pq2.top();
        pq2.pop();
        l1*=pq2.top();
        l1*=pq1.top();
        l2*=pq1.top();
        pq1.pop();
        l2*=pq1.top();
        pq1.pop();
        l2*=pq1.top();
        return max(l1,l2);
    }
};