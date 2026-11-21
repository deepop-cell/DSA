class Solution {
public:
int Size(int node , vector<vector<int>>&adj,vector<int>&ans){
    int total=0;
    for(auto &v:adj[node]){
        total+=Size(v,adj,ans);
    }
    ans[node]=1+total;
    return 1 + total;//post order dfs . 
}
void dfs(int node, vector<vector<int>>&adj,unordered_map<char,int>&mp,string &s,vector<int>&parent){
    char curr=s[node];
    bool existed=mp.count(curr);
    int prev=existed?mp[curr]:-1;
    if(mp.find(curr)!=mp.end()){
        parent[node]=mp[curr];
    }
        mp[curr]=node;//storing it //nearest for ahead ones .
    
    for(auto &v:adj[node]){
        dfs(v,adj,mp,s,parent);
    }
    if(existed){
        mp[curr]=prev;
    }
    else{
        mp.erase(curr);
    }
   
    return;
}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        unordered_map<char,int>mp;
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int>ans(n);
        dfs(0,adj,mp,s,parent);
        vector<vector<int>>newadj(n);
        for(int i=1;i<n;i++){
            newadj[parent[i]].push_back(i);
        }
        Size(0,newadj,ans);
        return ans;
    }
};