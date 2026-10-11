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
int dfs(TreeNode * root,int &moves){
    if(!root){
        return 0;
    }
    int leftextra=dfs(root->left,moves);
    int rightextra=dfs(root->right,moves);
    int curr=leftextra+rightextra + root->val -1;//(ek to apne paas rkhunga  baaki pass kr dunga upar).
    moves+=abs(curr);
    return curr;
}
    int distributeCoins(TreeNode* root) {
        int moves=0;
         dfs(root,moves);
         return moves;
    }
};