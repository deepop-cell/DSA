class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }//making map for diagonal traversal of matrix.
        for(auto &it:mp){
            sort(it.second.rbegin(),it.second.rend());//sorting them//sort(v.rbegin(),v.rend()) sorts in descending order.
        }
        //now filling them.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};