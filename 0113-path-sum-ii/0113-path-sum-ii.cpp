
class Solution {
public:
    void solve(int sum,TreeNode* root,vector<int>&temp,vector<vector<int>>&res){
        if(!root->left && !root->right){
            //leaf aa gya hai.
            if(sum==0){
                res.push_back(temp);
                return ;
            }
        }
        //now we can go left or go right.
        if(root->left){
            temp.push_back(root->left->val);
            solve(sum-root->left->val,root->left,temp,res);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->val);
            solve(sum-root->right->val,root->right,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<int>temp;
        temp.push_back(root->val);
        vector<vector<int>>res;
        solve(targetSum-root->val,root,temp,res);
        return res;
    }
};