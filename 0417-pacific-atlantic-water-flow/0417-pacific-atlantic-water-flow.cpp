class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>Reachable_Pacific(m,vector<int>(n,-1));
        vector<vector<int>>Reachable_Atlantic(m,vector<int>(n,-1));
        queue<pair<int,int>>q_a;
        queue<pair<int,int>>q_p;
        for(int j=0;j<n;j++){
            Reachable_Pacific[0][j]=1;
            q_p.push({0,j});
            Reachable_Atlantic[m-1][j]=1;
            q_a.push({m-1,j});
        }
        for(int i=0;i<m;i++){
            Reachable_Pacific[i][0]=1;
            q_p.push({i,0});
            Reachable_Atlantic[i][n-1]=1;
            q_a.push({i,n-1});
        }
        //now we will do bfs from the boundary and mark points .
        while(!q_p.empty()){
            int sz=q_p.size();
            for(int i=0;i<sz;i++){
                auto it=q_p.front();
                q_p.pop();
                int r=it.first;
                int c=it.second;
                //now we can discover 4 directions.
                //mai wahi ja skta hu jahaki height badi ya barabar hai.
                for(auto &dir:directions){
                    int next_r=r+dir[0];
                    int next_c=c+dir[1];
                    if(next_r<0 || next_r>=m || next_c<0 || next_c>=n){
                        //out of bounds check'
                        continue;
                    }
                    if(Reachable_Pacific[next_r][next_c]!=-1){
                        continue;//aleardy viisited node hai ye
                    }
                    if(heights[next_r][next_c]>=heights[r][c]){
                        //then we can go yaha
                        q_p.push({next_r,next_c});
                        Reachable_Pacific[next_r][next_c]=1;//marking that we can viist this one.
                    }
                }
            }
        }
        while(!q_a.empty()){
            int sz=q_a.size();
            for(int i=0;i<sz;i++){
                auto it=q_a.front();
                q_a.pop();
                int r=it.first;
                int c=it.second;
                //now we can discover 4 directions.
                //mai wahi ja skta hu jahaki height badi ya barabar hai.
                for(auto &dir:directions){
                    int next_r=r+dir[0];
                    int next_c=c+dir[1];
                    if(next_r<0 || next_r>=m || next_c<0 || next_c>=n){
                        //out of bounds check'
                        continue;
                    }
                    if(Reachable_Atlantic[next_r][next_c]!=-1){
                        continue;//aleardy viisited node hai ye
                    }
                    if(heights[next_r][next_c]>=heights[r][c]){
                        //then we can go yaha
                        q_a.push({next_r,next_c});
                        Reachable_Atlantic[next_r][next_c]=1;//marking that we can viist this one.
                    }
                }
            }
        }
        //now just check ki kkonse konse nodes dono se visit kr skte hai hum,
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(Reachable_Pacific[i][j]==1 && Reachable_Atlantic[i][j]==1){
                    //means yaha dono se aa skte hai
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};