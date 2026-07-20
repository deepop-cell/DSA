class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }
        int len=m*n;
        k=k%(len);
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            st.push(arr[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=st.top();
                st.pop();
            }
        }
        return grid;
    }
};