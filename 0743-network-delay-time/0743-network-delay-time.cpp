class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
    //first make an adjacnecy list
    for(auto &e:times){
        int u=e[0];
        int v=e[1];
        int wt=e[2];
        adj[u].push_back({v,wt});
    }
    vector<int>result(n+1,INT_MAX);
    result[k]=0;
    //make a minheap.
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,k});//dist , node.
    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto &temp:adj[node]){
            int adjnode=temp.first;
            int wt=temp.second;
            if(d+wt<result[adjnode]){
                result[adjnode]=d+wt;
                pq.push({d+wt,adjnode});
            }
        }

    }
    int max_time=0;
    for(int i=1;i<result.size();i++){
        if(result[i]==INT_MAX){
            //means node was never reached
            return -1;
        }
        else{
            max_time=max(max_time,result[i]);
        }
    }
    return max_time;
    }
};