class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       //so first we will find the shortesth path using dijkstra 
      int mod = 1e9 + 7;
       vector<vector<pair<long long, long long>>> adj(n);
       for(auto &x:roads){
        int a=x[0];
        int b=x[1];
        int wt=x[2];
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
       } 
       priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
       pq.push({0,0});
       vector<long long>dist(n,1e18);
       vector<long long>ways(n,0);
       dist[0]=0;
       ways[0]=1;
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        long long d=it.first;
        if(d>dist[node])continue;
        for(auto &temp:adj[node]){
            int adjnode=temp.first;
            long long wt=temp.second;
            if(d+wt<dist[adjnode]){
                dist[adjnode]=d+wt;
                pq.push({d+wt,adjnode});
                ways[adjnode]=ways[node];
            }
            else if(d+wt==dist[adjnode]){
                ways[adjnode]=((ways[node])+ways[adjnode])%mod;
            }
        }
       }
       return ways[n-1]%1000000007;
    }
};