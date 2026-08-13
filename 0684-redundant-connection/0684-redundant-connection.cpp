class Solution {
public:
//we will find cycle using dsu here/
int find(int x,vector<int>&parent){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x],parent);//rank compression/
}
void Union(int x, int y,vector<int>&parent,vector<int>&rank){
    int p1=find(x,parent);
    int p2=find(y,parent);
    if(p1!=p2){
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            //equal ranks hai to ek ko parent banado and just make one parent and inc its rank
            parent[p2]=p1;
            rank[p1]++;
        }
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //thius is a classic dsu question/
        vector<int>ans;
        int n=edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>rank(n+1,1);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int p1=find(u,parent);
            int p2=find(v,parent);
            if(p1==p2){
                //then is edge ko jodne se cycle bnegi/
                //we need to remove this edge
                return {u,v};
            }
            else{
                Union(u,v,parent,rank);
            }
        }
        return ans;
        
    }
};