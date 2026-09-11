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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* n_r= new TreeNode(val);
            n_r->left=root;
            n_r->right=NULL;
            return n_r;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        bool done=false;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            auto curr=q.front();
            q.pop();
                if(level==depth-1){
                    TreeNode* x=curr->left;
                    TreeNode* y=curr->right;
                    TreeNode* new_l=new TreeNode(val);
                    TreeNode* new_r=new TreeNode(val);
                    curr->left=new_l;
                    curr->right=new_r;
                    new_l->left=x;
                    new_r->right=y;
                }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }

            }
            level++;
        }
        return root;
    }
};