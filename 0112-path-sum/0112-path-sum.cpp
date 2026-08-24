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
public:
    bool solve(TreeNode* root,int sum){
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
            if(sum==0){
                return true;
            }
            return false;
        }
        //now we have options to go left or go right
        bool l=false;
        bool r=false;
        if(root->left){
           l= solve(root->left,sum-root->left->val);
        }
        if(root->right){
            r=solve(root->right,sum-root->right->val);
        }
        return r || l;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return solve(root,targetSum-root->val);
    }
};