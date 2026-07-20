class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>diff(n,vector<int>(n,0));
        //this question teaches us how to use difference array technique in 2d array...
        for(auto &x:queries){
            int r1=x[0];
            int c1=x[1];
            int r2=x[2];
            int c2=x[3];
            for(int i=r1;i<=r2;i++){
                diff[i][c1]+=1;
                if(c2+1<n){
                diff[i][c2+1]-=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            int csum=0;
            for(int j=0;j<n;j++){
                csum+=diff[i][j];
                diff[i][j]=csum;
            }
        }
        return diff;
    }
};