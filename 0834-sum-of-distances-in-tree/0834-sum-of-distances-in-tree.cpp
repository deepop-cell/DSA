class Solution {
public:
    void bfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&dist){
        vis[node]=true;
        dist[node]=0;
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
                        dist[v]=dist[curr]+1;
                    }
                }
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>>adj(n+1);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>count(n,1);
        vector<int>degree(n,0);
        queue<int>q;
        vector<int>vis3(n,false);
        for(int i=0;i<n;i++){
            degree[i]=adj[i].size();
            if(degree[i]==1 && i!=0){
                //leaves hai ye
                count[i]=1;
                q.push(i);
                vis3[i]=true;
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int currleaf=q.front();
                q.pop();
                for(auto &v:adj[currleaf]){
                    if(!vis3[v]){
                     count[v]+=count[currleaf];
                    degree[v]--;
                   if(degree[v]==1 && v!=0){
                    q.push(v);
                    vis3[v]=true;
                    }

                   }
                }
            }
        }
        //now first find the ans for base yaani 0.
        vector<bool>vis(n,false);
        vector<int>dist(n);
        bfs(0,adj,vis,dist);
        vector<int>ans(n,0);
        int ans_0=0;
        for(int i=0;i<dist.size();i++){
            ans_0+=dist[i];
        }
        ans[0]=ans_0;
        //ab hmare paaas 0 ka answeer hai. ab bakiyo ka nikalte hai.
        queue<int>q2;
        vector<int>vis2(n,false);
        q2.push(0);
        vis2[0]=true;
        while(!q2.empty()){
            int sz=q2.size();
            for(int i=0;i<sz;i++){
                int curr=q2.front();
                q2.pop();
                for(auto &v:adj[curr]){
                    if(!vis2[v]){
                        q2.push(v);
                        vis2[v]=true;
                    int ans_v=ans[curr]-count[v]+(n-count[v]);
                    ans[v]=ans_v;
                    }
                }
            }
        }
        return ans;
    }
};