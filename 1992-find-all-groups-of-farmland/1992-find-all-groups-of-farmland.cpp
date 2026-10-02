class Solution {
public: 
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    pair<int,int> bfs(int x,int y,vector<vector<int>>&land){
        pair<int,int> lastvisnode={-1,-1};
        land[x][y]=0;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                q.pop();
                lastvisnode={r,c};
                for(auto &dir:directions){
                    int newr=r+dir[0];
                    int newc=c+dir[1];
                    if(newr<0 || newr>land.size()-1 || newc<0 || newc>land[0].size()-1 || land[newr][newc]==0){
                        continue;
                    }
                    else{
                        q.push({newr,newc});
                        land[newr][newc]=0;
                    }
                }
            }
        }
        return lastvisnode;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    //farmland hai /
                    vector<int>temp={i,j};
                    auto it=bfs(i,j,land);
                    temp.push_back(it.first);
                    temp.push_back(it.second);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};