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
    if(!root->left && !root->right){
        return true;
    }
    return false;
}
void dfs(TreeNode * root,vector<TreeNode*>&res){
    if(!root){
        return;
    }
    if(isleaf(root)){
        res.push_back(root);
        return;
    }
    dfs(root->left,res);
    dfs(root->right,res);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*>res1;
        dfs(root1,res1);
        vector<TreeNode*>res2;
        dfs(root2,res2);
        if(res1.size()!=res2.size()){
            return false;
        }
        for(int i=0;i<res1.size();i++){
            if(res1[i]->val!=res2[i]->val){
                return false;
            }
        }
        return true;
    }
};