class Solution {
public:
void dfsfill(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){
    vis[node]=true;
    for(auto &v:adj[node]){
        if(!vis[v]){
            dfsfill(v,adj,vis,st);
        }
    }
    st.push(node);//pehle baccho ko dalo fir maa ko dalna.
}
void dfsmakescc(int node,vector<int>&currscc,vector<vector<int>>&adj,vector<bool>&vis){
    vis[node]=true;
    currscc.push_back(node);
    for(auto &v:adj[node]){
        if(!vis[v]){
            dfsmakescc(v,currscc,adj,vis);
        }
    }
}
    int longestCycle(vector<int>& edges) {
        stack<int>st;
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            adj[i].push_back(edges[i]);
        }
        vector<bool>vis(n,false);
        for(int u=0;u<n;u++){
            if(vis[u])continue;
            dfsfill(u,adj,vis,st);
        }
        //make rev adj.
        vector<vector<int>>revadj(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            revadj[edges[i]].push_back(i);
        }
        vector<bool>vis2(n,false);
        int mx=1;
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            if(!vis2[curr]){
                vector<int>currscc;
                dfsmakescc(curr,currscc,revadj,vis2);
                mx=max(mx,(int)currscc.size());
            }
        }
        return (mx==1)?-1:mx;
    }
};