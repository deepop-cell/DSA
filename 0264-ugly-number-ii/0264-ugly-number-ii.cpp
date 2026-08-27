class Solution {
public:
typedef long long ll;
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        unordered_set<ll>seen;
        pq.push(1);
        seen.insert(1);
        vector<int>ugly={2,3,5};
        ll curr=1;
        for(int i=0;i<n;i++){
             curr=pq.top();
            pq.pop();
            for(int &x:ugly){
                ll nextugly=curr*x;
                if(seen.find(nextugly)!=seen.end()){
                    //means this is already checked then continie/
                    continue;
                }
                pq.push(nextugly);
                seen.insert(nextugly);
            }
        }
        return curr;
    }
};