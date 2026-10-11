class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
    //first of all we need to find the number of childs of each node. to  uske liye we will use rerooting tree
    int n=parents.size();
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        if(parents[i]==-1){
            continue;
        }
        adj[parents[i]].push_back(i);
        adj[i].push_back(parents[i]);
    }    
    vector<int>deg(n);
    for(int u=0;u<n;u++){
        deg[u]+=adj[u].size();
    }
    queue<int>q;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(i!=0 && deg[i]==1){
            q.push(i);
            vis[i]=true;
        }
    }
    vector<int>child(n,1);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto currleaf=q.front();
            q.pop();
            for(auto &v:adj[currleaf]){
                if(vis[v]){
                    continue;
                }
                child[v]+=child[currleaf];
                deg[v]--;
                if(deg[v]==1 && v!=0){
                    //ab ye leaf ban gaya hai 
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    //ab dekhte hai kiska max hai . 
    vector<long long>ans;
    queue<int>q1;
    q1.push(0);
    vector<bool>vis1(n,false);
    vis1[0]=true;
    while(!q1.empty()){
        int sz=q1.size();
        for(int i=0;i<sz;i++){
            auto curr=q1.front();
            q1.pop();
            //ab iska ans ky aega 
            long long a=1;
            long long x=0;
            for(auto &v:adj[curr]){
                if(vis1[v]){
                    continue;
                }
                q1.push(v);
                vis1[v]=true;
                a*=1LL*(child[v]);
                x+=(child[v]);
            }
            if(curr!=0){
            a*=(1LL*(n-1-x));
            }
            ans.push_back(a);
        }
    }
    long long mx=-1;
    for(auto &x:ans){
        mx=max(mx,x);
    }
    int freq=0;
    for(auto &x:ans){
        if(x==mx){
            freq++;
        }
    }
    return freq;
    }
};