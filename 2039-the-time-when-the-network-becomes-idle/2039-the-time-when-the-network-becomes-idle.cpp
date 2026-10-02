class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<int>dist(n);
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dist[0]=0;
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                        dist[v]=dist[curr]+1;
                    }
                }
            }
        }
        //now we have shortest distance of every node from 0th node. 
        int mx=0;
        for(int u=1;u<n;u++){
            int rtt=2*dist[u];
            int last_msg_sent_time=((rtt-1)/patience[u])*patience[u];
            //this last message sent will decide time that will be last_msg_time + rtt .
    mx=max(mx,last_msg_sent_time+rtt+1);
        }
        return mx;
    }
};