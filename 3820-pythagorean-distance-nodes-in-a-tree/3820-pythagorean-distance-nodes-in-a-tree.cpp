class Solution {
public:  
    void bfs(int node,vector<int>&dist,int n,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vector<bool>vis(n,false);
        vis[node]=true;
        dist[node]=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        dist[v]=dist[curr]+1;
                        vis[v]=true;
                    }
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto &x:edges){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>depthX(n);
        vector<int>depthY(n);
        vector<int>depthZ(n);
        bfs(x,depthX,n,adj);
        bfs(y,depthY,n,adj);
        bfs(z,depthZ,n,adj);
        //now for every node we haveits dist from x , y and z.
        int cnt=0;
        for(int i=0;i<n;i++){
            int A=depthX[i];
            int B=depthY[i];
            int C=depthZ[i];
            if(1LL*A*A + 1LL*B*B == 1LL*C*C || 1LL*B*B + 1LL*C*C ==1LL*A*A || 1LL*A*A + 1LL*C*C == 1LL*B*B){
                cnt++;
            }
        }
        return cnt;
    }
};