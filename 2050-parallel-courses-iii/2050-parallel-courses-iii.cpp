class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
      //we need to find max running sum . 
      queue<pair<int,int>>q;
      vector<int>indegree(n+1,0);
      vector<vector<int>>adj(n+1);
      for(auto &e:relations){
        int a=e[0];
        int b=e[1];
        adj[a].push_back(b);
      }  
      for(int u=1;u<=n;u++){
        for(auto &v:adj[u]){
            indegree[v]++;
        }
      }
        unordered_map<int,long long >maxtime;

      for(int u=1;u<=n;u++){
        if(indegree[u]==0){
            maxtime[u]=time[u-1];
        q.push({u,time[u-1]});
        }
      }
      long long mx=-1;
      while(!q.empty()){
        auto it=q.front();
        int node=it.first;
        long long running_sum=it.second;
        mx=max(mx,running_sum);
        q.pop();
        for(auto &v:adj[node]){
            indegree[v]--;
            maxtime[v]=max(maxtime[v],running_sum+time[v-1]);
            if(indegree[v]==0){
            q.push({v,maxtime[v]});
            }
        }
      }
        return mx;
    }
};