class Solution {
public:
    int find(int x ,vector<int>&p){
        if(x==p[x])return x;
        return p[x]=find(p[x],p);
    }
    void Unite(int x,int y,vector<int>&p,vector<int>&r){
        int p1=find(x,p);
        int p2=find(y,p);
        if(p1!=p2){
            if(r[p1]>r[p2]){
                p[p2]=p1;
            }
            else if(r[p1]<r[p2]){
                p[p1]=p2;
            }
            else{
                p[p1]=p2;
                r[p2]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //intially Keep all edges removed and keep Uniting as in order and chek if current edge makes a cycle by using dsu find.
        int n=edges.size();
        vector<int>rank(n+1,1);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<vector<int>>ans;
        for(auto &x:edges){
        int u=x[0];
        int v=x[1];
        if(find(u,parent)==find(v,parent)){
            //donon ek hee grp ke h to ye edge se sycle aa jaega 
            ans.push_back({u,v});
        }
        else{
            Unite(u,v,parent,rank);
        }
        }
        return ans[ans.size()-1];
    }
};