class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        vector<vector<int>>adj(n);
       for(int i=0;i<properties.size();i++){
        unordered_set<int>mpa;
        for(auto  &x:properties[i]){
            mpa.insert(x);
        }
        for(int j=i+1;j<properties.size();j++){
            //ab find kro common elements.
            int cnt=0;
            unordered_set<int>seen;
            for(int &z:properties[j]){
                if(mpa.find(z)!=mpa.end() && seen.find(z)==seen.end()){
                    //means a mai b tha 
                    cnt++;
                }
                seen.insert(z);
            }
            if(cnt>=k){
                //matlab valid hai 
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       } 
        //ab find kro number of components.
        int comp=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i,adj,vis);
            }
        }
       return comp;
    }
};