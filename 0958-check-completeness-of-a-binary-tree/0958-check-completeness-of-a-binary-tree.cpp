
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool pastnull=false;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr){
                pastnull=true;
            }
            else{
                if(pastnull){
                    return false;
                }
                else{
                    q.push(node->left);
                    q.push(node->right);

                }
            }
        }
        return true;
    }
};