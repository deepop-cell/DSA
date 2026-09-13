class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n+1);
        for(auto &x:times){
            int a=x[0];
            int b=x[1];
            int wt=x[2];
            adj[a].push_back({b,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int d=it.first;
            if(d>dist[node]){
                continue;
            }
            for(auto &temp:adj[node]){
                int adjnode=temp.first;
                int wt=temp.second;
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            else{
                mx=max(mx,dist[i]);
            }
        }
        return mx;
    }
};