#include<iostream>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode*right;
};  
int findFloor(TreeNode* root, int key) {
    int floor = -1;

    while (root) {
        if (root->val == key)
            return root->val;

        if (root->val < key) {
            floor = root->val;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }

    return floor;
}