class Solution {
public:
    long long solve(int node,vector<vector<int>>&adj,bool skipped,vector<int>& values){
        //base case.
        if(adj[node].size()==0){//leaf aa gyi oye .
            if(skipped==false){
                return 0;//isse skip krdo
            }
            return values[node];
        }
        //now we have v options . (nbr ke ) i mean curr ko leke v explore . 
        // or current ko mat leke v expplore.
        //lets  take current.
        long long option1=values[node];
        for(auto &v:adj[node]){
        option1+=solve(v,adj,skipped,values);
        }
        // skip current one.
        long long option2=0;
        if(skipped==false){
            //skip nhi kia hoga tabhi nahi na exploree krenhe 
            for(auto &v:adj[node]){
                option2+=solve(v,adj,true,values);
            }
        }
        return max(option1,option2);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto &X:edges){
            int a=X[0];
            int b=X[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vector<vector<int>>radj(n);
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                        radj[curr].push_back(v);
                    }
                }
            }
        }
        bool skipped=false;
        return solve(0,radj,skipped,values);
    }
};