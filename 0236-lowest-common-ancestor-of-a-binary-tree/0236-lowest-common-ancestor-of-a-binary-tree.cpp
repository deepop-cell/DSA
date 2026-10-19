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
TreeNode* LCA(TreeNode* root,TreeNode* p, TreeNode* q){
    if(!root){
        return NULL;
    }
    if(root->val==p->val || root->val==q->val){
        return root;
    }
    auto L=LCA(root->left,p,q);
    auto R=LCA(root->right,p,q);
    if(L && R ){
        return root;//yehi lca hai 
    }
    if(L){
        return L;
    }
    if(R){
        return R;
    }
    return NULL;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
};