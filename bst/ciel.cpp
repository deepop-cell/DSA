#include<iostream>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode*right;
};
int findCeil(TreeNode* root, int key) {
    int ceil = -1;

    while (root) {
        if (root->val == key)
            return root->val;

        if (root->val > key) {
            ceil = root->val;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return ceil;
}