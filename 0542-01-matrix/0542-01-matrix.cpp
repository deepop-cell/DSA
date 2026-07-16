class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});//pushing all the cells having 0
                    dist[i][j]=0;//0  ka 0 se dist 0 hoga na/
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int r=it.first;
                int c=it.second;
                //ab sare neighbours ko discover karo..
                if(r>0 && mat[r-1][c]!=0){
                    if(dist[r-1][c]==-1){
                        dist[r-1][c]=dist[r][c]+1;
                        q.push({r-1,c});
                    }
                }
                if(r+1<m && mat[r+1][c]!=0){
                    if(dist[r+1][c]==-1){
                        dist[r+1][c]=dist[r][c]+1;
                        q.push({r+1,c});
                    }
                }
                if(c>0 && mat[r][c-1]!=0){
                    if(dist[r][c-1]==-1){
                        dist[r][c-1]=dist[r][c]+1;
                        q.push({r,c-1});
                    }
                }
                if(c+1<n && mat[r][c+1]!=0){
                    if(dist[r][c+1]==-1){
                        dist[r][c+1]=dist[r][c]+1;
                        q.push({r,c+1});
                    }
                }
            }
        }
        return dist;
        
    }
};