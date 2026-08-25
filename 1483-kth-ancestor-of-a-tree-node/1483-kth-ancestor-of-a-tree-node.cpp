class TreeAncestor {
public:
    int rows;
    int cols;
    vector<vector<int>>parent;
    vector<bool>vis;
    void dfs(int node,vector<vector<int>>&parent,int par,vector<bool>&vis,vector<vector<int>>&adj){
        vis[node]=true;
        parent[node][0]=par;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(v,parent,node,vis,adj);
            }
        }
    }
    TreeAncestor(int n, vector<int>& pt) {
        rows=n;
        cols=log2(n)+2;
        parent.assign(rows,vector<int>(cols,-1));
        vector<vector<int>>adj(n);
        vis.assign(n,false);
        for(int i=0;i<pt.size();i++){
            if(pt[i]==-1){
                continue;
            }
            adj[i].push_back(pt[i]);
            adj[pt[i]].push_back(i);
        }
        dfs(0,parent,-1,vis,adj);
        for(int j=1;j<cols;j++){
            for(int i=0;i<n;i++){
                if(parent[i][j-1]!=-1){
                    parent[i][j]=parent[parent[i][j-1]][j-1];
                }
                else{
                    parent[i][j]=-1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        //now see kitna chaiye hoga.
  for(int j=0;j<cols;j++) {
            if ((k>>j)&1) { // Agar k ka j-th bit 1 hai, toh 2^j steps jump maaro
                node=parent[node][j];
                if(node==-1) return -1; // Tree ke upar nikal gaye
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */