class Solution {
public:
    void dfsfill(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfsfill(v,adj,vis,st);
            }
        }
        st.push(node);//pehle baccho ko dal lo fir maa ko dalna.
    }
    void makescc(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&currscc){
        vis[node]=true;
        currscc.push_back(node);
        for(auto &v:adj[node]){
            if(!vis[v]){
                makescc(v,adj,vis,currscc);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        //we havr to find the length of the largest SCC.
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
           adj[i].push_back(edges[i]);
            }

        }
        //now make toposort orderf.
        stack<int>st;
        vector<bool>vis(n,false);
        for(int u=0;u<n;u++){
            if(!vis[u]){
                dfsfill(u,adj,vis,st);
            }
        }

        fill(vis.begin(),vis.end(),false);
        int mx=-1;
        vector<vector<int>>revadj(n);
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                revadj[v].push_back(u);
            }
        }
        //now our stack has the topoorder.
        //now do  dfs on the reversed edges graph in topoorde.r
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            if(!vis[curr]){
                vector<int>currscc;
                makescc(curr,revadj,vis,currscc);
                //now currscc is filled with the scc startinf from curr.
                if(currscc.size()>1){
                mx=max(mx,(int)currscc.size());
                }

            }
        }
        return mx;
    }
};