class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int &x:arr){
            mp[x]++;
        }
        auto it=mp.begin();
        while(it!=mp.end()){
            pq.push({it->second,it->first});
            it++;
        }
        //now our heap has max freq order/
        int x=arr.size();
        int op=0;
        while(x>arr.size()/2){
            x-=pq.top().first;
            op++;
            pq.pop();
        }
        return op;
    }
};