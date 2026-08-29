class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<int>degree(n);
       for(auto &edge:roads){
        int u=edge[0];
        int v=edge[1];
        degree[u]++;
        degree[v]++;
       } 
       vector<vector<bool>>isRoad(n,vector<bool>(n,false));
       for(auto &edge:roads){
        int a=edge[0];
        int b=edge[1];
        isRoad[a][b]=true;
        isRoad[b][a]=true;
       }
       //now traverse in graph
       int mx=INT_MIN;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(isRoad[i][j]){
                //there is road bw them.
                mx=max(mx,degree[i]+degree[j]-1);
            }
            else{
                mx=max(mx,degree[i]+degree[j]);
            }
        }
       }
       
       return mx;
    }
};