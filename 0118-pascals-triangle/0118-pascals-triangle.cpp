class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>level(i+1);
            level[0]=1;
            level[i]=1;
            for(int j=1;j<i;j++){
             level[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(level);
        }
        return ans;
    }
};