class Solution {
public:
int diameter(vector<vector<int>>&edges,int node,int&level){
    int E=edges.size();
    int n=E+1;
    vector<vector<int>>adj(n);
    for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//adjacency list.
    queue<int>q;
    vector<bool>vis(n,false);
    q.push(node);
    int farthestnode=node;
    vis[node]=true;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int currnode=q.front();
            farthestnode=currnode;
            q.pop();
            for(auto &v:adj[currnode]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;//mark true while pushing
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
        int one_end_edges1=diameter(edges1,0,x);
        int d1=0;
        diameter(edges1,one_end_edges1,d1);//this will make d1.
        int y=0;
        int one_end_edges2=diameter(edges2,0,y);
        int d2=0;
        diameter(edges2,one_end_edges2,d2);
        //return (d1+1)/2+(d2+1)/2+1;(this missed some test cases), because aoisa bhi ho skta ki diamater (yani longest path trees merge krne ke baad d1, ya d2 mai se  koi ek ho)
        int dmax=max(d1,d2);
        int dmerge=(d1+1)/2+(d2+1)/2+1;
        return max(dmax,dmerge);
    }
};