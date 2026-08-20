class Solution {
public:
    bool solve(int targetsum, TreeNode* root) {
        if (root == NULL) return false;
        targetsum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            if(targetsum==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool go_left = false;
        bool go_right = false;
        if (root->left != NULL) {
            go_left = solve(targetsum, root->left);
        }
        if (root->right != NULL) {
            go_right = solve(targetsum, root->right);
        }
        return (go_left || go_right);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(targetSum, root);
    }
};