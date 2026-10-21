/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void dfs(TreeNode* root,TreeNode * target, TreeNode* &t){
    if(!root){
        return;
    }
    if(root->val==target->val){
        t=root;
        return;
    }
    dfs(root->left,target,t);
    dfs(root->right,target,t);
}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* x=NULL;
        dfs(cloned,target,x);
        return x;
    }
};