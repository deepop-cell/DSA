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
    TreeNode* lca(TreeNode* root,int mx,unordered_map<TreeNode*,int>&depth){
        if(!root){
            return NULL;
        }
        if(depth[root]==mx){
            return root;
        }
        auto L=lca(root->left,mx,depth);
        auto R=lca(root->right,mx,depth);
        if(L && R){
            //yehi lca hai . 
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root){
            return root;
        }
        if(!root->right && !root->left){
            return root;
        }
        unordered_map<TreeNode*,int>depth;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    depth[curr->left]=depth[curr]+1;
                }
                if(curr->right){
                    q.push(curr->right);
                    depth[curr->right]=depth[curr]+1;
                }
            }
        }
        int mx=-1;
        for(auto &it:depth){
            mx=max(mx,it.second);
        }
        //noww we have pushed the deepest leavees.
        return lca(root,mx,depth);

    }
};