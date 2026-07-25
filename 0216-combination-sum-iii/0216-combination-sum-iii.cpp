class Solution {
public:
    void solve(int  i, int sum , vector<int>&temp,vector<vector<int>>&res,vector<int>&arr,int &k){
        if(sum==0){
            if(temp.size()==k){
            res.push_back(temp);
            }
            return;
        }
        if(i>=9){
            return;
        }
        //*********TAKE********
        if(arr[i]<=sum){
            temp.push_back(arr[i]);//lelo
            solve(i+1,sum-arr[i],temp,res,arr,k);
            temp.pop_back();//backtracking....
        }
        //********SKIP**********.
        solve(i+1,sum,temp,res,arr,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>res;
        vector<int>arr(9);
        for(int i=0;i<9;i++){
            arr[i]=i+1;
        }
        //ab solve wali chiz karo..
        solve(0,n,temp,res,arr,k);
        return res;
    }
};