class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &x:edges){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
//marking dist of all nodes from 0 **********
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        vector<int>dist(n);
        dist[0]=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        dist[v]=dist[curr]+1;
                        vis[v]=true;
                    }
                }
            }
        }
        int ans_0=0;
        for(auto &x:dist){
            ans_0+=x;
        }
//**********************************
//to find the number of  child , we will do leaf pulling.
    queue<int>q1;
    vector<int>deg(n,0);
    for(int u=0;u<n;u++){
        deg[u]+=(int)adj[u].size();
    }
    vector<bool>vis2(n,false);
    for(int i=1;i<n;i++){
        if(deg[i]==1){
            //means ki ye leaf hai.
            q1.push(i);
            vis2[i]=true;
        }
    }
    //ab leaf prunnig krna haii .
    vector<int>child(n,1);
    while(!q1.empty()){
        int sz=q1.size();
        for(int i=0;i<sz;i++){
            int currleaf=q1.front();
            q1.pop();
            for(auto &v:adj[currleaf]){
                if(vis2[v]){
                    continue;
                }
            child[v]+=child[currleaf];
            deg[v]--;
            if(deg[v]==1 && v!=0){
                q1.push(v);
                vis2[v]=true;
            }
            }
        }
        }
        //now its very easy 
        vector<int>ans(n,0);
        ans[0]=ans_0;
        //now start bfs and make answers.
        queue<int>q2;
        vector<bool>vis3(n,false);
        q2.push(0);
        vis3[0]=true;
        while(!q2.empty()){
            int sz=q2.size();
            for(int i=0;i<sz;i++){
                auto it=q2.front();
                q2.pop();
                for(auto &v:adj[it]){
                    if(vis3[v]){
                        continue;
                    }
                    q2.push(v);
                    ans[v]=ans[it]+n-2*child[v];
                    vis3[v]=true;
                }
            }
        }
        return ans;
    }
};