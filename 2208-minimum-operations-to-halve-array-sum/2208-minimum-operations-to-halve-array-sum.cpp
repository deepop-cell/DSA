class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum=0;
        for(int &x:nums){
            pq.push(x);
            sum+=x;
        }
        double halve=sum/2;
        int op=0;
        while(sum>halve){
            double t=pq.top();
            sum-=(t/2.0);
            pq.push(t/2.0);
            pq.pop();
            op++;
        }
        return op;
    }
};