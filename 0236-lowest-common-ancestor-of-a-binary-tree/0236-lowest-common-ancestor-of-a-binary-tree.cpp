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
bool ispath(TreeNode* root,vector<TreeNode*>&path,TreeNode* target){
    if(!root){
        return false;
    }
    path.push_back(root);
    if(root->val==target->val){
        return true;
    }
    bool l=ispath(root->left,path,target);
    if(l){
        return true;
    }
    bool r=ispath(root->right,path,target);
    if(r){
        return true;
    }
    path.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1;
        vector<TreeNode*>p2;
        ispath(root,p1,p);
        ispath(root,p2,q);
        TreeNode* lca=nullptr;
        for(int i=0;i<min(p1.size(),p2.size());i++){
            if(p1[i]==p2[i]){
                lca=p1[i];
            }
            else{
                break;
            }
        }
        return lca;
    }
};