class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool>vis(n,false);
        vis[headID]=true;
        vector<vector<int>>adj(n);
        for(int i=0;i<manager.size();i++){
            if(i==headID){
                continue;
            }
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        int mx=INT_MIN;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front().first;
                int time=q.front().second;
                mx=max(mx,time);
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push({v,time+informTime[curr]});
                        vis[v]=true;
                    }
                }
            }
        }
        return mx;
    }
};