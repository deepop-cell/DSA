class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        //first thing to observe is that, agar hum leaf ko hataye , to ans n-1 aa rha h.
        //wrna baaki ke liye see, 
        // prouct of child of all unvis nbrs *(n-x-1) where x is sigma of child of all unvis v.
        int n=parents.size();
        vector<int>child(n,1);
        vector<int>deg(n,0);
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        queue<int>q;
        vector<bool>vis(n,false);
       for(int u=0;u<n;u++){
        deg[u]=(int)adj[u].size();
       }
       for(int i=1;i<n;i++){
        if(deg[i]==1){
            q.push(i);
            vis[i]=true;
        }
       }
       while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int currleaf=q.front();
            q.pop();
            for(auto &v:adj[currleaf]){
                if(vis[v]){
                    continue;
                }
                child[v]+=child[currleaf];
                deg[v]--;
                if((deg[v]==1 && v!=0 )|| ( v==0 && deg[v]==0)){//now its leaf
                    q.push(v);
                    vis[v]=true;
                }
            }

        }
       }
       //now calcualting ans.
       vector<long long >ans(n);
       queue<int>q2;
       q2.push(0);
       vector<bool>vis2(n,false);
       vis2[0]=true;
       while(!q2.empty()){
        int sz=q2.size();
        for(int i=0;i<sz;i++){
            auto it=q2.front();
            q2.pop();
            //ab isko cut kiya to kya hoga ans??? lets see.
            long long x=0;
            long long a=1;
            for(auto &v:adj[it]){
                if(vis2[v]){
                    continue;
                }
                q2.push(v);
                vis2[v]=true;
                x+=child[v];
                a*=1LL*child[v];
            }
            if(it!=0){
            a*=1LL*(n-x-1);
            }
            ans[it]=a;
        }
       }
       long long mx=*max_element(ans.begin(),ans.end());
       int cnt=0;
       for(int i=0;i<n;i++){
        if(ans[i]==mx){
            cnt++;
        }
       }
       return cnt;
    }
};