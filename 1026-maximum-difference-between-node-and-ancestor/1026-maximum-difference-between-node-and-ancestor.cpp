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
int dfs(TreeNode* root,int curr_min,int curr_max){
    if(!root){
        return curr_max-curr_min;
    }
    curr_max=max(curr_max,root->val);
    curr_min=min(curr_min,root->val);
    int left=dfs(root->left,curr_min,curr_max);
    int right=dfs(root->right,curr_min,curr_max);
    return max(left,right);
}
    int maxAncestorDiff(TreeNode* root) {
        int a=dfs(root,root->val,root->val);
        return a;
    }
};