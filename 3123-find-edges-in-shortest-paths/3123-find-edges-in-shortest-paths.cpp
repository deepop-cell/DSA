class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
       vector<vector<array<int, 3>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt,i});
            adj[v].push_back({u,wt,i});
        }
        priority_queue<pair<long long , int>,vector<pair<long long , int>>,greater<pair<long long , int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int node=curr.second;
            long long d=curr.first;
            if(d>dist[node])continue;
            for(auto &temp:adj[node]){
                int adjnode=temp[0];
                long long wt=temp[1];
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }
        //now start bfs from last one and check krterho 
        vector<bool>ans(edges.size(),false);
        queue<int>q;
        q.push(n-1);
        vector<bool>vis(n,false);
        vis[n-1]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &t:adj[curr]){
                int x=t[0];
                int wt=t[1];
                int id=t[2];
                if(dist[x]!=LLONG_MAX && dist[x]+wt==dist[curr]){
                    ans[id]=true;
                if(!vis[x]){
                    q.push({x});
                    vis[x]=true;
                }
                }
            }
        }
        return ans;
    }
};