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
void dfs(TreeNode* root,vector<int>&inorder){
    if(!root){
        return;
    }
    dfs(root->left,inorder);
    inorder.push_back(root->val);
    dfs(root->right,inorder);
}
    int minDiffInBST(TreeNode* root) {
        //do pre order traversal that is sorted order of the bst , then find min adjacent differnce.
        vector<int>inorder;
        dfs(root,inorder);
        int mn=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++){
            mn=min(mn,inorder[i+1]-inorder[i]);
        }
        return mn;
    }
};