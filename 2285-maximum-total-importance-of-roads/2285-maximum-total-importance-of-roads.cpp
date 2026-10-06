class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(auto &edges:roads){
            int a=edges[0];
            int b=edges[1];
            degree[a]++;
            degree[b]++;
        }
        priority_queue<pair<int,int>>pq;//degree , node (og).
        for(int i=0;i<n;i++){
            pq.push({degree[i],i});
        }
        int a=n;
        unordered_map<int,int>mp;
        while(n>=1){
            int curr=pq.top().second;
            mp[curr]=n;
            n--;
            pq.pop();
        }
        long long sum=0;
        for(auto &edge:roads){
            int a=edge[0];
            int b=edge[1];
            sum+=mp[a]+mp[b];
        }
        return sum;
    }
};