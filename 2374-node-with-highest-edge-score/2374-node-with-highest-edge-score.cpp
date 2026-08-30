class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }
        unordered_map<int,long long>mp;
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                mp[v]+=u;
            }
        }
        auto it=mp.begin();
        long long bestscore=-1;
        int node=-1;
        while(it!=mp.end()){
         if(it->second>bestscore){
            bestscore=it->second;
            node=it->first;
         }
         it++;
        }
        auto x=mp.begin();
        while(x!=mp.end()){
            if(x->second==bestscore && x->first<node){
                node=x->first;
            }
            x++;
        }   
        return node;
    }
};