class Solution {
public:
// i will treat it as a graph.
    int diameter(int node,vector<vector<int>>&adj,vector<bool>&vis,int &level){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        int farthestnode=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            int x=q.front();
            vis[x]=true;
            farthestnode=x;
            q.pop();  
            for(auto &v:adj[x]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
            }
            if(!q.empty()){
            level++;
            }
        }
        return farthestnode;
    }
    void depthmaking(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&depth){
         queue<int>q;
        q.push(node);
        vis[node]=true;
        depth[node]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int y=q.front();
                q.pop();
                for(auto &v:adj[y]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                        depth[v]=depth[y]+1;
                    }
                }
            }
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int d=1;
        int farthest_node1=diameter(0,adj,vis,d);
        vector<bool>vis1(n,false);
        diameter(farthest_node1,adj,vis1,d);
        //now d has the value of h.
        long long ans=0;
        vector<bool>vis2(n,false);
        vector<int>depth(n);
        depthmaking(0,adj,vis2,depth);
        for(int i=0;i<n;i++){
            ans+=1LL*(nums[i])*(d-depth[i]+1);
        }
        return ans;
    }
};