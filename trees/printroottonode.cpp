#include<iostream>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:

    bool findPath(TreeNode* root, int x, vector<int>& path) {

        if(root == NULL)
            return false;

        path.push_back(root->val);

        if(root->val == x)
            return true;

        if(findPath(root->left, x, path))
            return true;

        if(findPath(root->right, x, path))
            return true;

        path.pop_back();

        return false;
    }

    vector<int> rootToNodePath(TreeNode* root, int x) {

        vector<int> path;

        findPath(root, x, path);

        return path;
    }
};