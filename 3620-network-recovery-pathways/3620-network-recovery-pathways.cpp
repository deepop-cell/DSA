class Solution {
public:
typedef long long x;
bool check(int mid, int n,x k,vector<vector<vector<int>>> &adj){
priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
    vector<x>result(n,LLONG_MAX);
    result[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        x d=it.first;
        int node=it.second;
        if(d>result[node]){
            //optimisation
            continue;
        }
        if(d>k){
            return false;//abhi hee k se bada ho gya to aage to lund kam nhi hoga.
        }
        if(node==n-1){
            return true;//hell yea you got the end and its valid path.
        }
        for(auto &vec:adj[node]){
            int cost=vec[1];
            int adjnode=vec[0];
            if(cost<mid){
            //ab to mid minimum yani score ho hee nhi payga so skip this path.
            continue;
            }
            if(d+cost<result[adjnode]){
                result[adjnode]=d+cost;
                pq.push({d+cost,adjnode});
            }
        }
        
    }
    //agar bahar aa gye dijkstra ke to falsel
    return false;

}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, x k) {
        int n=online.size();
        //now make ajacency list ignoring the offline paths.
        int l=INT_MAX;
        int r=INT_MIN;
        int ans=-1;
        vector<vector<vector<int>>> adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(wt<l){
                l=wt;//low of bs is min edge cost/
            }
            if(wt>r){
                r=wt;//max edge cost is r
            }
            if(!online[u] || !online[v]){
                //ek node offline hai is path ka , just skip it.
                continue;
            }
            adj[u].push_back({v,wt});
        }//adjancency list ban gai hai.
        //binary search kro abs answer par.
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,n,k,adj)){
                //agar ye true hua .. then socho , mid is the minscore then we need to maximise it, hence search in the right
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;

            }
        }
        return ans;
        
    }
};