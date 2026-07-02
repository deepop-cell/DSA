class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>health_max(m,vector<int>(n,-1));
        int start_health=health-grid[0][0];
        if(start_health<=0){
            return false;
        }
        //else 
        health_max[0][0]=health-grid[0][0];
        pq.push({health_max[0][0],{0,0}});
        while(!pq.empty()){
            //dekho health matrix mai initially sab -1 hai to agar nextheralth 0 hua to wo bhi update ho jayga but humari health 0 se badi hee honi chaiye. hence check nexthealth>0 before exploring neighbours,
            auto it=pq.top();
            pq.pop();
            int curr_health=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==m-1 && c==n-1){
                return true;
            }
            if(r+1<m){
                int next_health=curr_health-grid[r+1][c];
                if( next_health>0 && next_health>health_max[r+1][c]){
                    health_max[r+1][c]=next_health;
                    pq.push({next_health,{r+1,c}});
                }
            }
            if(r>0){
                int next_health=curr_health-grid[r-1][c];
                if(next_health>0 && next_health>health_max[r-1][c]){
                    health_max[r-1][c]=next_health;
                    pq.push({next_health,{r-1,c}});
                }
            }
            if(c+1<n){
                int next_health=curr_health-grid[r][c+1];
                if(next_health>0 && next_health>health_max[r][c+1]){
                    health_max[r][c+1]=next_health;
                    pq.push({next_health,{r,c+1}});
                }
            }
            if(c>0){
                int next_health=curr_health-grid[r][c-1];
                if(next_health>0 && next_health>health_max[r][c-1]){
                    health_max[r][c-1]=next_health;
                    pq.push({next_health,{r,c-1}});
                }
            }
            
         }
         return false;//heap khali ho gayi aur corner pe aa hee nahi paaye tum.
    }
};