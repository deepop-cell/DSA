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
    bool ispath(TreeNode* root,vector<TreeNode*>&path,int target){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root->val==target){
            return true;
        }
        //we have two options to go /
        if(ispath(root->left,path,target)){
            return true;
        }
        if(ispath(root->right,path,target)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        ispath(root,path1,p->val);
        ispath(root,path2,q->val);
        TreeNode* LCA=NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i]==path2[i]){
                LCA=path1[i];
            }
            else{
                break;
            }
        }
        return LCA;

    }
};