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
bool ispath(TreeNode* root,int target,vector<TreeNode*>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root);
    if(root->val==target){
        return true;
    }
    if(ispath(root->left,target,path) || ispath(root->right,target,path)){
        return true;
    }
    path.pop_back();//bakctracking mai use ho jaygii..
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        ispath(root,p->val,path1);
        ispath(root,q->val,path2);
        int i=0;
        int j=0;
        TreeNode* lca=NULL;
        while(i < path1.size() && j < path2.size()&& path1[i]->val==path2[j]->val){
            lca=path1[i];
            i++;
            j++;
        }
        return lca;
    }
};