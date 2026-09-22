
class Solution {
public:
unordered_map<TreeNode*,vector<int>>dp;
    int solve(TreeNode* curr,bool parent){
        if(!curr){
            return 0;
        }
        if(dp.find(curr)==dp.end()){
        dp[curr] = vector<int>(2, -1);
        }
        if(dp.find(curr)!=dp.end() && dp[curr][parent]!=-1){
            return dp[curr][parent];
        }
        int rob=0;
        if(!parent){
            //means we can rob this house
        rob=curr->val;
        rob+=solve(curr->left,true);
        rob+=solve(curr->right,true);
        }
        int dontrob=solve(curr->left,false)+solve(curr->right,false);
        return dp[curr][parent]=max(rob,dontrob);
    }
    int rob(TreeNode* root) {
       return solve(root,false); 
    }
};