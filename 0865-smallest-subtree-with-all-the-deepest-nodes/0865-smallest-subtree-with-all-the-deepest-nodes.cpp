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
    void dfs(TreeNode* root, int d , unordered_map<TreeNode*,int >&depth,int&mx){
        if(!root){
            return;
        }
        depth[root]=d;
        mx=max(mx,d);
        dfs(root->left,d+1,depth,mx);
        dfs(root->right,d+1,depth,mx);
    }
    TreeNode* LCA(TreeNode* root,int mx,unordered_map<TreeNode*,int>&depth){
        if(!root){
            return NULL;
        }
        if(depth[root]==mx){
            return root; //yaha wo dekho jo tum search lr rhe ho.
        }
        auto L=LCA(root->left,mx,depth);
        auto R=LCA(root->right,mx,depth);
        if(L && R ){
            //dono trf jo chaoye wo hai to yehi to lca hoga na 
            return root;
        }
        if(L){
            return L;
        }
        if(R){
            return R;
        }
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,int>depth;
        int d=0;
        int mx=-1;
        dfs(root,d,depth,mx);
    return LCA(root,mx,depth);
    }
};