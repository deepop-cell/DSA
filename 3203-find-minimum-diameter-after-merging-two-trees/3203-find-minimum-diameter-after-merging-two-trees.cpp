class Solution {
public:
int diameter(vector<vector<int>>&edges,int node,int &level){
    int E=edges.size();
    int n=E+1;//no of nodes =edges.size()+1
    vector<vector<int>>adj(n);
    vector<bool>vis(n+1,false);
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);//undriected graph.
    }
    int farthestnode=node;
    queue<int>q;
    q.push(node);
    vis[node]=true;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            farthestnode=q.front();
            q.pop();
            for(auto &v:adj[farthestnode]){
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


    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int x=0;
        int one_edge_d1=diameter(edges1,0,x);
        int d1=0;
        diameter(edges1,one_edge_d1,d1);
        int y=0;
        int one_edge_d2=diameter(edges2,0,y);
        int d2=0;
        diameter(edges2,one_edge_d2,d2);
        int dmax=max(d1,d2);
        return max(dmax,(d1+1)/2 +(d2+1)/2+1);

      
    }
};