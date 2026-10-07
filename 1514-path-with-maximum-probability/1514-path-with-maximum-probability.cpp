class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>>pq;//maxheap//prob, node.
        pq.push({1,start});
        vector<double>prob(n,0);
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            double p=succProb[i];
            adj[a].push_back({b,p});
            adj[b].push_back({a,p});
        }
        prob[start]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double p=it.first;
            int node=it.second;
            for(auto &temp:adj[node]){
                int adjnode=temp.first;
                double pp=temp.second;
                if(p*pp>prob[adjnode]){
                    prob[adjnode]=p*pp;
                    pq.push({p*pp,adjnode});
                }
            }
        }
    return prob[end];
    }
};