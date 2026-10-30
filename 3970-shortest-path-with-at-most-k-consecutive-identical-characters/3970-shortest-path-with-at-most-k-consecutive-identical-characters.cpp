class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        //dijkstra hee lgega but wo additional condition ka  kya scene h , first of all we will keep a track of curr consective  seen so far . also dist array will be a 2d array not one d here, since for a city there  can be many ways of rwaching so dist[node][x] where x means no of consectiuve seen so far.
        vector<vector<pair<int,int>>>adj(n);
        for(auto &E:edges){
            int a=E[0];
            int b=E[1];
            int wt=E[2];
            adj[a].push_back({b,wt});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,1}});
        // isme humne dala hai dist, node , consective seen so far.
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        dist[0][1]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second.first;
            int d=it.first;
            int cons=it.second.second;
            for(auto &T:adj[node]){
                int adjnode=T.first;
                int wt=T.second;
                    //first check to krlo ki consectuve k se jyada bada na ho jaye.
                    if(labels[adjnode]==labels[node] && cons==k){
                        continue;
                    }
                    else if(labels[adjnode]==labels[node] && d+wt<dist[adjnode][cons+1]){
                        pq.push({d+wt,{adjnode,cons + 1}});
                        dist[adjnode][cons+1]=d+wt;
                    }
                    else if(labels[node]!=labels[adjnode] && d+wt<dist[adjnode][1]){
                        //when unequal reset cons to 1.
                        pq.push({d+wt,{adjnode,1}});
                        dist[adjnode][1]=d+wt;
                    }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<=k;i++){
            mn=min(mn,dist[n-1][i]);
        }
        return (mn==INT_MAX)?-1:mn;
    }
};