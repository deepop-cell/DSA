/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    typedef long long ll;
public:
    
    ll solve(TreeNode* root,ll sum){
        if(root==NULL){
            return 0;
        }
        int count=(sum==0)?1:0;
        ll go_left=0;
        //now decide.
        if(root->left){
            go_left=solve(root->left,sum-root->left->val);
        }
        ll go_right=0;
        if(root->right){
            go_right=solve(root->right,sum-root->right->val);
        }
        return count+ go_left+go_right;
    }
    void dfs(TreeNode* root,int&ans,ll sum){
        if(!root){
            return;
        }
        ans+=solve(root,sum-root->val);
        dfs(root->left,ans,sum);
        dfs(root->right,ans,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ways=0;
        dfs(root,ways,targetSum);
        return ways;
    }
};