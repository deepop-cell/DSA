class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<int>dist(n,-1);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(auto &x:edges){
            int a=x[0];
            int b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        q.push(0);
        dist[0]=price[0];
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(dist[v]==-1){
                        q.push(v);
                        dist[v]=dist[curr]+price[v];
                    }
                }
            }
        }
            int A=-1;
            int mx=*max_element(dist.begin(),dist.end());
            for(int i=0;i<n;i++){
            if(dist[i]==mx){
                A=i;
                break;
            }
            }
            //now find the farthest one from A 
            vector<int>dist2(n,-1);
            dist2[A]=price[A];
            q.push(A);
            while(!q.empty()){
                auto curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(dist2[v]==-1){
                        dist2[v]=dist2[curr]+price[v];
                        q.push(v);
                    }
                }
            }
            int mx2=*max_element(dist2.begin(),dist2.end());
            int B=-1;
            for(int i=0;i<n;i++){
                if(dist2[i]==mx2){
                    B=i;
                    break;
                }
            }
            vector<int>distA(n,-1);
            vector<int>distB(n,-1);
            distA[A]=price[A];
            distB[B]=price[B];
            q.push(A);
            while(!q.empty()){
                int sz=q.size();
                for(int i=0;i<sz;i++){
                    auto curr=q.front();
                    q.pop();
                    for(auto &v:adj[curr]){
                        if(distA[v]==-1){
                            distA[v]=distA[curr]+price[v];
                            q.push(v);
                        }
                    }
                }
            }
                q.push(B);
            while(!q.empty()){
                int sz=q.size();
                for(int i=0;i<sz;i++){
                    auto curr=q.front();
                    q.pop();
                    for(auto &v:adj[curr]){
                        if(distB[v]==-1){
                            distB[v]=distB[curr]+price[v];
                            q.push(v);
                        }
                    }
                }
            }
        
            int ans=INT_MIN;
            for(int u=0;u<n;u++){
                int option1=distA[u]-price[u];
                int option2=distB[u]-price[u];
                int maxxx=max(option1,option2);
                ans=max(ans,maxxx);
            }
            return ans;
    }
};