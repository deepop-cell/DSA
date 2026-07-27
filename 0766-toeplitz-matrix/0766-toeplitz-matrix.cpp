class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(matrix[i][j]);
            }
        }
        for(auto &it:mp){
            int check=-1;
            for(int &val:it.second){
                if(check==-1){
                    check=val;
                }
                else{
                    if(val!=check){
                        return false;
                    }
                }

            }
        }
        return true;
    }
};