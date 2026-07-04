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
  vector<int>inorder;
  void dfs(TreeNode* root){
    if(root==NULL){
        return ;
    }
    dfs(root->left);
    inorder.push_back(root->val);
    dfs(root->right);
  }

    
    bool isValidBST(TreeNode* root) {
        dfs(root);
        int n=inorder.size();
        for(int i=0;i<n-1;i++){
            if(inorder[i+1]<=inorder[i]){
                return false;
            }
        }
        return true;
    }
};