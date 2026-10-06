class Solution {
public:
vector<int> depth(int node,vector<vector<int>>&adj,vector<bool>&vis){
    vis[node]=true;
    int n=adj.size();
    vector<int>depth(n);
    depth[node]=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            for(auto &v:adj[it]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    depth[v]=depth[it]+1;
                }
            }
        }
    }
    return depth;
}
  int diameter(int node,vector<vector<int>>&adj,vector<bool>&vis,int &h){
    queue<int>q;
    q.push(node);
    vis[node]=true;
    int lastvis=-1;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
    lastvis=it;
    q.pop();
    for(auto &v:adj[it]){
        if(!vis[v]){
            q.push(v);
            vis[v]=true;
        }
    }
        }
        if(!q.empty()){
        h++;
        }
    }
    return lastvis;

  }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>>adj(n);
    for(auto &x:edges){
        int a=x[0];
        int b=x[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }  
    int x=0;
    vector<bool>vis(n,false);  
    int one_end=diameter(0,adj,vis,x);
    int d=0;
    vector<bool>vis2(n,false);
   int other_end= diameter(one_end,adj,vis2,d);
    //if d is even .
    vector<bool>vis3(n,false);
    vector<int>depthA=depth(one_end,adj,vis3);
    vector<bool>vis4(n,false);
    vector<int>depthB=depth(other_end,adj,vis4);
    if(d%2==0){
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(depthA[i]+depthB[i]==d && depthA[i]==d/2){
            ans.push_back(i);
        }
    }
    return ans;
    }
    else{
        //odd depth hai .
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(depthA[i]+depthB[i]==d && abs(depthA[i]-depthB[i])==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
    return {};
    }
};