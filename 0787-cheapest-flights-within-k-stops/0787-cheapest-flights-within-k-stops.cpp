class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:flights){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }//adjacnecy list.
        vector<int>result(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,src});
        while(!q.empty() && k>=0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int node=it.second;
            int d=it.first;
            for(auto &temp:adj[node]){
                int adjnode=temp.first;
                int wt=temp.second;
                if(d+wt<result[adjnode]){
                    result[adjnode]=d+wt;
                    q.push({d+wt,adjnode});
                }
            }
            }
            k--;//after traversing one level
        }
        if(result[dst]==INT_MAX){
            return -1;
        }
        else{
            return result[dst];
        }
    }
};