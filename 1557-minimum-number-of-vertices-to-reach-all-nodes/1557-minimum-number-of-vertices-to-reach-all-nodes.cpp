class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //just rereturn the nodes which have indegree 0.
        vector<vector<int>>adj(n);
        for(auto &x:edges){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
        }
        vector<int>indegree(n);
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }
        //v
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};