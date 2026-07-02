class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int oldcolor=image[sr][sc];
        image[sr][sc]=color;//color the current cell
        if(oldcolor==color){
            return image;
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            //now discover all the neighbours
            if(r+1<m && image[r+1][c]==oldcolor){
                image[r+1][c]=color;
                q.push({r+1,c});
            }
            if(r>0 && image[r-1][c]==oldcolor){
                image[r-1][c]=color;
                q.push({r-1,c});
            }
            if(c+1<n && image[r][c+1]==oldcolor){
                image[r][c+1]=color;
                q.push({r,c+1});
            }
            if(c>0 && image[r][c-1]==oldcolor){
                image[r][c-1]=color;
                q.push({r,c-1});
            }
        }
        return image;
    }
};