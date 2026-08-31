class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    int maxDepth = 0;
    int bfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        int depth=0;
        vis[node]=true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
            if(!q.empty()){
                depth++;
            }
        }
        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>vis(n+1,false);
        int depth=bfs(1,adj,vis);
        return power(2,depth-1);
        
    }
};