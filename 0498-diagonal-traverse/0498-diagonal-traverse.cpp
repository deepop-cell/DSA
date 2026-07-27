class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //jab bhi diagnaol trvaersal ki bat aae to i-j and i+j yad aana chaiye.
        int m=mat.size();
        int n=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        //observe when i+j is even then we need to reverse the map entries/
        int totaldiag=m+n-1;
        vector<int>res;
        for(int k=0;k<totaldiag;k++){
            if((k%2)==0){
                reverse(mp[k].begin(),mp[k].end());
            }
            //if odd then keep it as it is.
            for(int &val:mp[k]){
                res.push_back(val);
            }
        }
        return res;
    }
};