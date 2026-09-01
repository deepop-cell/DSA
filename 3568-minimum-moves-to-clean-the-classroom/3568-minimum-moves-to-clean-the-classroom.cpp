class Solution {
public:
struct Jankari{
    int r;
    int c;
    int E;
    int collectedMask;
};
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int initial_energy=energy;
        int litterBit[20][20];
        int litter_c=0;
        int x=0;
        int y=0;
        int z=0;//this marks pos of litter
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    x=i;
                    y=j;
                }
                else if(classroom[i][j]=='L'){
                    litter_c++;
                    litterBit[i][j]=z;
                    z++;
                }
            }
        }
        int allcollected=(1<<litter_c)-1;//2 ka power litter_c -1.
        if(litter_c==0){
            return 0;
        }
        vector<vector<vector<vector<bool>>>>vis(
    m,
    vector<vector<vector<bool>>>(
        n,
        vector<vector<bool>>(
            initial_energy+1,
            vector<bool>(1<<litter_c,false)
        )
    )
);
        queue<Jankari>q;
        q.push({x,y,initial_energy,0});
        vis[x][y][initial_energy][0]=true;
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                int current_r=it.r;
                int current_c=it.c;
                int current_energy=it.E;
                int current_mask=it.collectedMask;
                q.pop();
                if(current_mask==allcollected){
                    //means we have colleted all the litters.
                    return moves;
                }
                if(current_energy==0){
                    continue;//galat raste aa gye babu/
                }
                for(auto &dir:directions){
                    int next_r=current_r+dir[0];
                    int next_c=current_c+dir[1];
                    int mask=current_mask;
                    int next_energy=current_energy-1;//ek move mai ek energy giregi.
                    if(next_r<0 || next_c<0 || next_r>=m || next_c>=n){
                        continue;
                    }
                    char cell=classroom[next_r][next_c];
                    if(cell=='X'){
                        continue;
                    }
                    else if(cell=='L'){
                       mask|=(1<<litterBit[next_r][next_c]);
                    }
                    else if(cell=='R'){
                        next_energy=initial_energy;//reser krdo energy ko.
                    }
                    if(!vis[next_r][next_c][next_energy][mask]){
                       vis[next_r][next_c][next_energy][mask]=true;
                       q.push({next_r,next_c,next_energy,mask});
                    }
                }

            }
            moves++;
        }
        return -1;//upar return nhi kia to yaha krdo -1
    }
};