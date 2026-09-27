class Solution {
public:
   int bfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int  n){
    queue<int>q;
    int dist=0;
    q.push(node);
    vis[node]=true;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
        int curr=q.front();
        q.pop();
        if(curr==n-1){
            return dist;
        }
        for(auto &v:adj[curr]){
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
            }
        }
        }
        dist++;
    }
    return -1;

   }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto &x:queries){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
            vector<bool>vis(n,false);
            int d=bfs(0,adj,vis,n);
            ans.push_back(d);
        }
        return ans;        
    }
};