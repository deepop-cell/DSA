class Solution {
public:
    int find(int x,vector<int>&parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
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
                parent[p1]=p2;
                rank[p2]++;
            }
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>rank(n+1,1);
        for(int i=1;i<=n;i++){
            if(i<=threshold){
                continue;
            }
            //jitne bhi mutlipes hai i ke unpe jao.
            int j=2*i;
            while(j<=n){
                Union(i,j,parent,rank);
                j+=i;
            }
        }
        //now queries ko dekho.
        vector<bool>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(find(u,parent)!=find(v,parent)){
                ans[i]=false;
            }
            else{
                ans[i]=true;
            }
        }
        return ans;
    }
};