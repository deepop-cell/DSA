class Solution {
public:
    void dfsfill(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfsfill(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    void dfs_traversal(int node,vector<vector<int>>&revadj,vector<bool>&vis,int &len){
        vis[node]=true;
        len++;
        for(auto&v:revadj[node]){
            if(!vis[v]){
                dfs_traversal(v,revadj,vis,len);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        stack<int>st;
        //first we will make adjacncy list.
        int n=edges.size();
       vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
            adj[i].push_back(edges[i]);
            }
        }
        //now call dfs fill for filling stakc with toporder.
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsfill(i,adj,vis,st);
            }
        }
        // Step 4: Reset visited array for the second pass
        fill(vis.begin(), vis.end(), false);
        //now reverse the edges.
        vector<vector<int>>revadj(n);
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                revadj[v].push_back(u);
            }
        }
        //now do bfs in toporder.
        int max_cycle_len=-1;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                int curr_cycle_len=0;
                dfs_traversal(node,revadj,vis,curr_cycle_len);
                if(curr_cycle_len>1){//to avoid single node scc.
                max_cycle_len=max(max_cycle_len,curr_cycle_len);
                }
            }
        }
        return max_cycle_len;
    }
};