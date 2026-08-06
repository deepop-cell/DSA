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
bool isleaf(TreeNode* root){
    if(!root){
        return false;
    }
    return (root->right==NULL && root->left==NULL);
}
void dfs(TreeNode* root,int&sum){
    if(!root){
        return;
    }
    dfs(root->left,sum); 
    if(isleaf(root->left)){
        sum+=root->left->val;
    }
    dfs(root->right,sum);
}
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root,sum);
        return sum;

        
    }
};