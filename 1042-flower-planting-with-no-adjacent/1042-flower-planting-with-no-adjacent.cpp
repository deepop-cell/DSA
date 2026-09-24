class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>colour(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto &p:paths){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //now just traverse the graph.
        for(int i=1;i<=n;i++){
         vector<bool>used(5,0);
         for(auto &v:adj[i]){
            if(colour[v]!=0){
                used[colour[v]]=1;
            }
         }
         for(int j=1;j<=4;j++){
            if(!used[j]){
                colour[i]=j;
                break;
            }
         }
            
        }
        colour.erase(colour.begin());//first wala to hai hee nhi plants are from 1 to n
        return colour;
    }
};