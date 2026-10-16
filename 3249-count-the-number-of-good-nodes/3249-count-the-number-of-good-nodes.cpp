class Solution {
public: 
    int subtree(int node, vector<vector<int>>&adj,int &count){
        int check=-1;
        int currsize=1;
        int nbrsize=0;
        bool right=true;
        for(auto &v:adj[node]){
            int x=subtree(v,adj,count);
            if(check==-1){
                check=x;
            }
            else{
                if(x!=check){
                    right=false;
                }
            }
         nbrsize+=x;
        }
        if(right){
        count++;
        }
        return currsize+nbrsize;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto & X:edges){
         int a=X[0];
         int b=X[1];
         adj[a].push_back(b);
         adj[b].push_back(a);
        }
        vector<vector<int>>radj(n);
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                for(auto &v:adj[it]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                        radj[it].push_back(v);
                    }
                }
            }
        }
        int cnt=0;
        subtree(0,radj,cnt);
        return cnt;
    }
};