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
    void dfs(TreeNode* root,vector<TreeNode*>&inorder){
        if(!root){
            return;
        }
        dfs(root->left,inorder);
        inorder.push_back(root);
        dfs(root->right,inorder);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){
            return root;
        }
        vector<TreeNode*>inorder;
        dfs(root,inorder);
        int i=0;
        TreeNode* head=new TreeNode(inorder[0]->val);
        TreeNode* temp=head;
        while(i<inorder.size()-1){
            temp->left=NULL;
            temp->right=inorder[i+1];
            temp=temp->right;
            i++;
        }
        inorder.back()->left=NULL;
        inorder.back()->right=NULL;
        return head;
    }
};