
class Solution {
public:
    void solve(TreeNode* root,int sum,vector<int>&temp,vector<vector<int>>&res){
        if(root->left==NULL && root->right==NULL){
            if(sum==0){
                res.push_back(temp);
                return;
            }
        }
        if(root->left){
            temp.push_back(root->left->val);
            solve(root->left,sum-root->left->val,temp,res);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->val);
            solve(root->right,sum-root->right->val,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<int>temp;
        vector<vector<int>>res;
        temp.push_back(root->val);
        solve(root,targetSum-root->val,temp,res);
        return res;
    }
};