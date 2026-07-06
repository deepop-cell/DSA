class Solution {
public:
    int minimumCost(vector<int>& cost) {

        priority_queue<int> pq;

        for(int x : cost)
            pq.push(x);

        int ans = 0;

        while(!pq.empty()) {

            ans += pq.top();
            pq.pop();

            if(!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }

            if(!pq.empty()) {
                pq.pop();   // free candy
            }
        }

        return ans;
    }
};