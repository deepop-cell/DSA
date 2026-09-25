class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++){
            auto x=equations[i];
            string u=x[0];
            string v=x[1];    
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1.0/values[i]});     
        }
        vector<double>ans;
        for(auto &q:queries){
            string a=q[0];
            string b=q[1];
            if(adj.find(a)==adj.end() || adj.find(b)==adj.end()){
                ans.push_back(-1);
            }
            else{
                unordered_map<string,bool>vis;
        queue<pair<string,double>>q;
        q.push({a,1});
        vis[a]=true;
        double as=-1;
        bool found=false;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front().first;
                double product=q.front().second;
                if(curr==b){
                found=true;
                as=product;
                break;
                }
                q.pop();
                for(auto &temp:adj[curr]){
                    if(!vis[temp.first]){
                        q.push({temp.first,product*temp.second});
                        vis[temp.first]=true;
                    }
                }
                
            }
            if(found){
                break;
            }
        }
    ans.push_back(as);
            }
        }
        return ans;
    }
};