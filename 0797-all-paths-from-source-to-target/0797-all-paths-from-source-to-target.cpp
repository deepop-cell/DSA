class Solution {
public:
    void solve(int u,vector<vector<int>>&adj,vector<vector<int>>&res,vector<int>&temp){
        if(u==adj.size()-1){
            //means we have reached the end.
            res.push_back(temp);
            return;
        }
        //else we have option to visit all enighbours.
        for(auto & v:adj[u]){
            //we try to visit this neighbour.
            temp.push_back(v);
            solve(v,adj,res,temp);
            temp.pop_back();//bakctracking , jo kia usko undo bhi karo.
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<vector<int>>res;
        vector<int>temp;
        temp.push_back(0);
        solve(0,adj,res,temp);
        return res;

    }
};