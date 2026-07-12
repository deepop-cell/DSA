class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank=1;
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:arr){
            pq.push(x);
        }
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            if(mp.find(x)==mp.end()){
                mp[x]=rank;
                rank++;

            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        
        return arr;
    }
};